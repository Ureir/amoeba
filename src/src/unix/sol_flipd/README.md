> [!NOTE]
>	
>	README	1.1	96/02/27 11:49:34
>

# A brief sketch of the streams-based FLIP driver for Solaris 2.x

On Solaris 2.x the FLIP device driver is a loadable STREAMS driver.
User programs that use the Solaris FLIP driver should be linked with
the `UNIX_STREAMS` version of `libamunix.a`. This library implements the
**trans()**, **getreq()** and **putrep()** RPC functions on top of **putmsg**(2) and
**getmsg**(2) calls into the FLIP driver. Only the FLIP RPC functions and
the **flip_stat()** and **flip_dump()** functions are implemented in the
Solaris 2.x FLIP driver.

The file `vdflip.c` contains the STREAMS driver entry points like
**\_init()**, **\_fini()**, **\_info()**, **flgetinfo()**, **flidentify()**, **flattach()** and
**fldetach()**.  When the FLIP driver is loaded into the kernel the **\_init()**
function is called. This is where the FLIP initialization is done and
the timers are set and started. After **\_init()** the function **flattach()**
is called. When the FLIP driver is unloaded the function **fldetach()** is
called, followed by a call to **\_fini()**.

The FLIP driver is initialized by starting a user level daemon
(flipd).  This daemon opens the `/dev/le` and the `/dev/flip_rpc0` driver
special files and links the Lance Ethernet driver under the FLIP
driver. The FLIP driver has an upper read queue to receive stream
messages from **putmsg**(2) system calls from user space. It has an upper
write queue to send stream messages to user space which the user can
get by calling **getmsg**(2). It has a lower write queue which will be
linked by the flipd daemon to the upper read queue of the Lance
Ethernet driver and a lower read queue which will be linked to the
upper write queue of the Lance Ethernet driver.

The file `ux_int.c` contains the **open()**, **close()** and **fluwput()** routines.
The FLIP driver is opened by the clone mechanism. Only one special file
exists for the FLIP driver. This is called `/dev/flip_rpc0` for backwards
compatibility with the SunOS 4.1.x FLIP driver. The FLIP driver picks a
free minor device and assigns this to the new thread.

For RPC specific calls the functions in the file `ux_rpc_int.c` are
called. These consist mainly of **flrpc\_open()**, **flrpc\_close()** and
**handle\_rpc()**.  **handle_rpc()** makes calls to **secure\_trans()**, **rpc\_getreq()**
and **rpc_putrep()** in the file `flrpc.c`.

The RPC heart of the FLIP driver is implemented as a state machine in
the file `flrpc.c` When a user process makes a call to the FLIP driver
a free minor device is sought and a queue (or kernel thread) is
started for that user process. For every minor device there is a data
structure (rpc\_device) which contains some private data for that queue,
such as the buffer containing the data copied into or out of the kernel.

The host interface functions **trans()** and **putrep()** contain a buffer
which contains data to be sent. A pointer to this buffer is stored in
the rpc\_device structure of the thread. At the network interface level
(in **flsend()**) the data from this buffer is copied into the stream
message to be sent to the Lance Ethernet driver. When the data is too
large to fit into one Ethernet packet the fragment code breaks up
the data into several fragments and takes care of the transmission and
possible retransmissions.  Only when it is certain that the other side
has received the data is this buffer freed.

For the data received from the network a similar situation exists. The
**trans()** and **getreq()** functions contain a buffer where the data should
be copied to.  Again, a pointer to this buffer is saved in the
rpc\_device structure for the thread. When the RPC code receives a
message it copies the data to this buffer. When several fragments
arrive the data is copied to the proper part of the buffer.

The **trans()** RPC is implemented at user level as a **putmsg**(2) followed by
a **getmsg**(2). The **putmsg**(2) contains a control message structure and a
data message structure.

The control message structure contains an rpc\_args structure which
contains the size of the data buffer copied into the kernel and the
size of the buffer in which the reply must be returned. It also contains
the send and receive headers. These headers contain among other things,
the port of the server to which the **trans()** call must be made.

The data message contains the data to be sent to the server.

The **putmsg**(2) converts the control and data messages into a stream
message and sends it to the stream head. The stream head calls the
**fluwput()** routine of the FLIP driver.  **fluwput()** calls **handle\_rpc()**
which calls **secure\_trans()**. First the port cache is checked to see if
the port of the server to be called is already known.

If the port is already in the cache, the state is set to `PUTREQ`,
**deliverreq()** is called and the driver returns to user space.

If the port is not known, the state is set to `LOCATE`, **findserver()** is
called and the driver returns to user space.

When a thread is in a `LOCATE` state, either a timer can expire or a
`RPC_HEREIS` packet for that `LOCATE` can arrive. When an `RPC_HEREIS` packet
arrives, the thread sets its state to `PUTREQ` and continues with a
**deliverreq()**. When a timer expires, the `RPC_LOCATE` packet is sent
again. When no `RPC_HEREIS` packet has arrived after a couple of tries a
**qreply()** with a return value of `RPC_NOTFOUND` is returned to the user
process. The **getmsg**(2) call of the user process returns with this
value.

When a thread is in a `PUTREQ` state either a timer can expire or an
`RPC_REPLY` can arrive. When an `RPC_REPLY` arrives the return value is set to
the size of the reply and the driver returns to user space with a **qreply()**.
When a timer expires the driver sends an `RPC_RECIEVED` message to ask the
other side if the request has been received.  If it gets an `RPC_NAK` its
sends the request again. If it gets a `RPC_ACK` its waits for the reply
again. If no reply to the `RPC_RECEIVED` is received it is assumed the server
is dead and the driver returns to user space with status `RPC_FAILURE`.

The **getreq()** RPC is implemented at the user level as a **putmsg**(2) which
only installs the port that the server will listen to in the FLIP driver.
After that a **getmsg**(2) is done to receive a request from a client.  The
state of the thread is set to `GETREQ`. When an `RPC_REQUEST` arrives the
driver returns to user space and returns the size of the request.

The **putrep()** RPC is implemeted at user level as a **putmsg**(2) with header,
count and buffer arguments. The data is sent in an `RPC_REPLY` packet to the
client and the state is set to `PUTREQ`. When it gets an `RPC_ACK` from the
client, the driver returns and the user space **getmsg**(2) is unblocked with
an `STD_OK` status. If no reply is received by the client and a timer
expires, the `RPC_REPLY` packet is sent again. If after a couple of tries no
`RPC_ACK` has been received, the driver returns to user space with status
`RPC_FAILURE`.

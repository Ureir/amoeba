> [!NOTE]
> Copyright 1994 Vrije Universiteit and Stichting Mathematisch Centrum,
>
>	README	1.3	94/04/06 11:37:06
>
> The Netherlands.
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

October 29, 1991

The after keyword was implemented which should make the bootserver
less painfully slow when booting.

It must be said that looking at the code, there is only one thing to do
with this thing, and that is to throw it away. The code is disgusting.

	Hans van Staveren

This file explains which extentions to the bootserver are desirable.
I don't have time to implement this myself, regrettably.

First there is a plain bug: I've never seen the bootserver dump
core successfully. `pd\_preserve` complaints about an invalid argument,
but of course it is unclear who discovers the problem in the first
place. Send a negative stun to a random X-server at CWI (the VU
uses a different setup) to reproduce the problem. Grep on "HIRO".
Another bug is the server's usage of the size of the datafile
(the one containing process capabilities) on the vdisk. It mallocs
memory this big if it want to store process capabilities, which can
be a problem if the vdisk is big. `Iboot` does something foolish with
it as well.


Then the design.

Contrary to what one might think naivily, the boot server cannot
assume that it simply has to reboot everything when it starts up:
  - It may have crashed itself, and be restarted
  - Not all of the system may have crashed.
    For instance, at CWI we run the runserver on
    bhi, not on mark (where the bootserver runs)

Consequently, it has to poll every service prior to starting it.
This makes rebooting a whole system slow: it has to see several
`RPC\_NOTFOUND`s, which takes a timeout (BTW, this is done by three
threads in parallel to ease the pain).

In reality, services depend on each other, which is currently
ignored by the server. For example, it makes no sense to attempt
to start a runserver before soap is available. You wouldn't even
find the binary (unless you want to hardcode its capability).
Peter has reported this problem in MR #111.

Currently, the bootserver will attempt to start the services in
the order in which they appear in the bootfile, but this is merely
an artefact of the implementation, and depend on picking the right
pollrates as well. Something well defined would be usefull.
I suggest adding the productions:
```
	option: 'depends-on' IDENT { ',' IDENT }* ';'
```
with the effect that the service won't be polled or started until
all services on which it depends are available. This would cut down
the number of timeouts before anything is started dramatically.

Once this is implemented, (and not before this time,) an exponential
backoff scheme could stop the server from repeating the same error
message over and over again. The server has to reset the currently
used timeinterval in **impl\_boot\_reinit()**.

An independent change that is required is to move the parser to iboot.
Right now, you'd better know what you're doing if you edit a bootfile.
(Ask Peter about his struggle with the semicolon...)

An alternative is to drop the whole server, and use the SAK server.
But then, it _has_ to be able to work without a directory server...

	Siebren

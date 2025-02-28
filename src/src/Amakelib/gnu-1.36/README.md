> [!NOTE]
> Copyright :copyright:1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.4	94/04/06 10:35:43
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

This directory contains a tool definition for "cc-c" suitable to be used
with gcc version 1.36.
To avoid having to call a seperate dependency-generator, we let the gcc
frontend call the ACK C-preprocessor, which gives the information we want.

As the gcc preprocessor gets called in a non standard way, we have to
fiddle the argument list and redirect its output first.
This is done by the small program `cvtcpp.c`, residing in this directory.

It should be installed in directory `$ACKCPPLIB` (by default `/usr/local/ambin`,
see `cc-c.amk`) under the name `gcc-cpp`.  The `-B` option of gcc then takes
care of picking this preprocessor instead of the default one.

Warning: the gcc toolset is currently **unsupported**, and has hardly
been tested.  We did manage to make a working Amoeba kernel with it, though.
Note also that this toolset is specifically for gcc **version 1.36**,
which is the only version we've got installed at this moment.
Expect to run into trouble with other versions: the cpp might be given
different parameters, in which case `cvtcpp.c` must be changed accordingly.

So: use at own risk, and only if you must.

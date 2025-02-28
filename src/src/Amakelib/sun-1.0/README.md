> [!NOTE]
> Copyright 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.2	94/04/06 10:37:04
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

This directory contains tool definitions to be used with "Sun C 1.0"
(aka "unbundeled") compiler.  It is actually just a minor variation
of the normal "sun" toolset.

The major difference is that we have removed the default `-O` flag
because that turned out to be "too smart" when compiling the Amoeba kernel.
So, in order to get a fast kernel, it is probably wise to use the
old Sun C compiler while you still have it.

Of course, some day we will try to track down what is really causing
the problem, and when we've fixed (or circumvented) it the `-O` option
will be added again.

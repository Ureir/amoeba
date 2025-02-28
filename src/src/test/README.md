> [!NOTE]
> Copyright 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.3	94/04/06 17:32:48
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

Amoeba contains a comprehensive suite of test programs for verifying
correct behaviour of most Amoeba utilities, functions and system calls.

This subtree contains the sources for making the Amoeba test programs.
It is a copy of the main source directory tree, so that each test
program, _x_, is located in a path under this subtree that corresponds to
the path of the source code for the thing that _x_ tests.
For example, `./kernel/server/bullet` contains the source for programs
to test the bullet server, since the source for the bullet server
itself is in `src/kernel/server/bullet`.

There are templates for configuring the test suite under the tree
`templates/test`. 

Under Amoeba the test binaries are typically installed under
`/public/module/test`.

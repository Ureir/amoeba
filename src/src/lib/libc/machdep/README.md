> [!NOTE]
> Copyright 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.2	94/04/07 10:34:57
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

Since it is possible to write very efficient assembly language versions of
many of the routines in libc there is a `generic` directory with C
implementations of all the routines that can be written in C.  (Some things
can only be written in assembler).  In addition there is a subdirectory
for each supported architecture.  If there is no special assembly language
version of a routine then the `Amake.srclist` file takes the generic version so it is
only necessary to take the subtree for the required architecture when building
the libraries.

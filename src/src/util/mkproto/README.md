> [!NOTE]
>	
>	README	1.1	91/04/09 17:04:47
>

This directory contains the mkproto program.
To make it:
If you do not have a working version of Amake but you do have Unix make:

copy the Makefile to a configuration directory and edit the CONF\_ROOT and
SRC\_ROOT lines at the top of the makefile to point at the configuration
and source directories respectively.

If you already have a version of amake then just use the template in the
amoeba configuration tree.  (The Amakefile here is just the source list
and not sufficient to build the object.)

Greg Sharp

The rest of the file is the original README file that came with mkproto

> Here is mkproto, a program for generating prototype declarations for all
> functions appearing in a C source file. The input C code may be either
> K&R or ANSI C (i.e. it's OK if the functions are defined using prototypes).
> Unlike some of the sed-based scripts floating around, it correctly
> handles prototype promotion (e.g. the prototype for `int foo() char x;...`
> is `int foo(int x)`). Also, it should work OK on just about any computer,
> not just Unix-based ones (it's been tested under minix, Unix, and TOS).
>
> Use: typically, you would type `mkproto *.c >proto.h` and then add a
> `#include "proto.h"` line to all the C source files. An ANSI conformant
> compiler will then be able to do type checking on function calls across
> module boundaries. As a bonus, `proto.h` will tell you which source files
> functions were defined in, and (if you gave the `-n` function to mkproto)
> their line numbers. The resulting include file may also be used by
> non-ANSI compilers; you can disable this feature (for cleaner, strictly
> ANSI-conforming output) with the `-p` flag.
>
> Please read the description of bugs in mkproto.man; definitely mkproto
> will not handle all programs correctly, but it does work on the majority of
> them. A sample of its output is provided in the file "mkproto.h"; this
> is the result of `mkproto mkproto.c >mkproto.h`.
>
> There is ABSOLUTELY NO WARRANTY for the program; as I said, it doesn't work
> on all programs (complicated function definitions can make it produce bogus
> output). It does what I need, though, and it can certainly make porting stuff
> to ANSI compilers easier.
>
> Mkproto is in the public domain. If you find any bugs (other than the ones
> documented) please let me know.
> --
> Eric R. Smith                     email:
> Dept. of Mathematics            ersmith@uwovax.uwo.ca
> University of Western Ontario   ersmith@uwovax.bitnet
> London, Ont. Canada N6A 5B7
> ph: (519) 661-3638

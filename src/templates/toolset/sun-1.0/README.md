> [!NOTE]
> Copyright 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.2	94/04/05 17:10:37
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

This directory contains include files for customizing the configuration
files.  The idea is that per Configuration object type you can customize
the choice of compiler, assembler, loader, archiver and lint.
This is done per object type because of the variation between choices of
flags for libraries, kernels, etc.

The compiler here is the unbundled sun 1.0 C Compiler.

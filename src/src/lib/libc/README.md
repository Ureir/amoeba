> [!NOTE]
> Copyright 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.2	94/04/07 10:21:41
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

The libc directory is divided up as follows:

## `machdep`
	Contains routines which could conceivably be written in
	assembly code (for efficiency or because they can't be done in
	C).  The generic subdirectory contains the C code version which
	can be used in the absence of an assembly code version.
	The ConfDef file is done per architecture.
    
## `misc`
	Contains routines for stdlib things which are not in the
	machdep subtree and anything faintly miscellaneous.

## `stdio`
	Contains routines for the ANSI C stdio library.  Currently
	this is implemented in terms of posix system calls.

## `ajax`
	Contains routines needed to make the stdio library and misc
	routines work.  This in fact a partial posix emulation.  The
	rest of it is in the ajax library.  If we do a direct
	implementation of stdio then this directory may become
	unnecessary.

## `time`
	Contains ansi C and un\*x time commands.

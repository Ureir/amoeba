> [!NOTE]
> Copyright 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.2	94/04/07 09:39:31
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

Since the Amoeba protocol may be run in a Unix[^1] kernel, Amoeba servers and
utilities may also run on Unix systems.  This requires two separate Amoeba
libraries: one for Amoeba systems and one for Unix systems that support the
Amoeba transaction protocol.
In addition we have a library for emulating Unix system calls which allows
many Unix utilities to be run on native Amoeba systems.

The library sources are structured as follows:

ajax
		Unix emulation and related functions for Amoeba.

libam
		System independent Amoeba convenience functions.

libc
		System independent C/Unix functions.

libmath
		System independent math library functions.

stubs
		Server stubs.

sysam
		Amoeba system call stubs for Amoeba plus system dependent
		convenience functions.

../unix/lib
		Amoeba system call stubs for Unix plus system dependent
		convenience functions.

From these sources five (5) libraries are generated:

libkernel.a
		Contains objects generated from libam, (subset of) libc, stubs.
		Used by Amoeba kernels.

libmath.a
		Contains objects generated from libmath.
		Used by user mode Amoeba and Unix servers and utilites.

libamoeba.a
		Contains objects generated from libam, libc, stubs, sysam.
		Used by user mode servers and utilities running under native
		Amoeba.

libamunix.a
		Contains objects generated from libam, stubs, `../unix/lib`.
		Used by user mode Amoeba servers and utilities running under
		Unix systems supporting the Amoeba transaction protocol.

libajax.a
		Contains objects generated from ajax.
		Used by programs running under Amoeba that want to make Unix
		system and library calls.

In addition the `head.o` file sources are stored in the directory head,
each one in a subdirectory for its architecture.  (`head.o` is prepended
to native amoeba programs - servers and utilities.)

[^1]: Unix is a trademark of AT&T

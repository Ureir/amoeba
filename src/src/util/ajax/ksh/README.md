> [!NOTE]
>	
>	ReadMe	1.2	92/05/13 11:41:49
>
		Public Domain KornShell

	Quick installation notes for PD KornShell

PD KornShell can be installed on 4.2+ BSD systems, System V, and
POSIX-compatable systems.  The makefiles all define `_BSD`, change
this to `_SYSV`, or `_POSIX`.  The makefiles also contain `CC=gcc`,
delete this if you don't have GNU C.  The ksh makefile also
contains some options, including `JOBS` (BSD/POSIX job control)
and `EDIT` (emacs command editing).

PD KornShell assumes you have standard C (ANSI) and POSIX header
files and functions. Since you probably don't, they are provided
in the `std` directory.

The Alpha test version will probably come as two tar files.
std.tar contains standard C and POSIX emulation and must be
extracted into a directory called `std`.  `ksh.tar` contains the ksh
source and should be extracted into a directory called `src` or
`ksh`.

See `std/ReadMe` and install it. Only then can you `make ksh` in the
`src` directory.

To clear up questions about the origin of this shell, this shell
is NOT based on the "Minix shell".  It is based on Charles
Forsyth's public domain V7 shell, which he later contributed to
Minix.

I have permission directly from Charles Forsyth to use his shell.

	Eric Gisin, egisin@math.UWaterloo.CA (or Waterloo.EDU)

	Things to do
- add sxt-based job control (see Brown's contribution on the Usenix 87 tape).
- add arrays and variable attributes.
- add `MAILPATH` and `CDPATH`.
- add `vi` editing mode (apparently someone has a PD version).
- add new features described in Korn's book.

	Machines ported to
VAX, 68000, 80386

	OS's ported to
BSD 4.2, BSD 4.3 (with and without YP and NFS
Sys V.3

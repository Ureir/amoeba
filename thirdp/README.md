> [!NOTE]
> File:		/home/amoeba5.3/thirdp/README
> 
> Last modified:	Fri Apr 12 15:41:02 MET DST 1996

This directory contains various items of third party software.
They are provided "as is".  They probably work but we make no
promises.  The various programs may have restrictions on
commercial use and/or redistribution.  Do not use anything you
are no legally entitled to, lest you be prosecuted by the owners
of the software.

All files are tar format.  The sizes given below are of the
uncompressed tar file.

The following are third-party *sources* and should be untarred in
\`amdir\`/thirdp

```
  Name		 Size	    Description
tcsh-6.04.tar    1.8 MB The sources for tcsh with support for Amoeba.
			Note that command typeahead is flushed - rather
			irritating.
mawk             750 KB	A clone of awk.  You need mawk to build the sparc
			port under Amoeba.  Bawk isn't good enough.
minix            950 KB Things like ed, ic and elle.
mmdf               6 MB The original mmdf mail systems sources
mtools20.am.tar  228 KB i80x86 tools for accessing MS-DOS floppies.
patch            180 KB The program patch for installing source code patches.
python.tar	   6 MB The sources for python and the modifications for
			Amoeba.  (The binaries, etc are already in the main
			distribution)

The following are binaries.  See the notes for each file for where
to install it.

gcc.am.tar	10.2 MB	The native Amoeba binaries for gcc 2.7,
			including assembler and linker (i80386 and sparc)
			Extract this in directory /super/module
orca.tar	16.8 MB	Binary distribution of the programming language
			Orca developed at the VU (i80386 and sparc).
			Extract this in directory /super/module
```

-----
Sums:
```
06731  5353 gcc.am.tar.Z
24371   171 grep-2.0.tar.Z
47937   254 mawk.Z
63591   385 minix.Z
33337  3773 mmdf.tar.Z
01805    79 mtools20.am.tar.Z
35380  4643 orca.tar.gz
11505    74 patch.Z
25883   708 tcsh-6.04.tar.Z
```

> [!NOTE]
> File:		/home/amoeba5.3/unix/README
>
> Last modified:	Tue Apr  9 13:20:38 MET DST 1996

This directory contains the binaries and drivers that run under various
versions of SunOS.

N.B. If you want to compile the Amoeba binaries for the sparc architecture
     under UNIX you will need the file ../thirdp/Ugnu.tar.Z

# SunOS 4.x

    WARNING: This is the last version of Amoeba for which SunOS 4
	     binaries will be provided or supported.

    The file SunOS_4.tar.Z contains all that you need for SunOS 4.x:
    Device drivers, plus binaries for Sun3s and Sun 4s which run
    SunOS 4.0.3 or newer versions.
    It also contains the ACK 386 cross-compiler which runs under
    SunOS on SPARC processors.

    The uncompressed tar file is about   8.65 MB.

## Installation Instructions

    SunOS_4.tar should be untarred at the top level of the Amoeba tree
    under UNIX.

    The "binaries" actually consist of binaries (in the directories bin.sun3
    and bin.sun4) and a directory called bin.scripts.  The scripts directory
    actually only contains symlinks to the shell scripts in the source tree
    so it is also necessary to untar the source tree at the same place!


# SunOS 5.4 / Solaris 2.4

    WARNINGS: 1. This driver does not work on Solaris 2.3 or 2.2.
	      2. It is a BETA test version.

    The distribution consists of the following files:
```
    name	     size	   description
Sol_bin.tar	    10.16 MB	The utilities for Solaris 2.4 and higher.
				It contains the following subdirectories:
				   bin.scripts - command scripts
				   bin.sol     - SPARC binaries for Solaris
				   bin.i86pc   - i80x86 binaries for Solaris.
Sol_sparc_drv.tar  376.00 KB	The FLIP driver for the SPARC version of
				Solaris.
```

    The bin.scripts directory actually only contains symlinks to the shell
    scripts in the source tree so it is also necessary to untar the source
    tree at the same place!
    The FLIP driver for the i86pc version of Solaris will be made available
    as soon as possible.

## Installation Instructions

    1. Install the UNIX binaries:

       In the following, BINDIR is the place where you install your
       Amoeba distribution.  If you already have the SunOS flip driver
       then this will be the directory /usr/proj/amwork.

```
    cd $BINDIR
    tar xf Sol_bin.tar
```

    2. Second install the FLIP driver:

    In the following example we assume PKGDIR is where you store the driver
    packages.  Typically this is /usr/local/packages.

    If you already have a Solaris FLIP driver installed then remove the
    old version:

```
    pkgrm VUCSflipu
    pkgrm VUCSflipr
```

    Now install the new package:

```
    cd $PKGDIR
    tar xf Sol_sparc_drv.tar  # this creates 2 directories: VUCSflipu & VUCSflipr.
    pkgadd -d  VUCSflipu
    pkgadd -d  VUCSflipr
```

    Now you can either reboot your machine or run the following command:

```
    /etc/init.d/flip-init start
```


# Checksums
```
47414  3736 Sol_bin.tar.Z
00012   143 Sol_sparc_drv.tar.Z
61862  3447 SunOS_4.tar.Z
```

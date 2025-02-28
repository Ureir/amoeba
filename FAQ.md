> [!NOTE]
> File:		`/home/amoeba5.3/FAQ`
>
> Last modified:	Thu Apr 11 10:16:05 MET DST 1996

This file attempts to answer frequently asked questions.  Few questions
keep recurring so it is short.  No doubt it will grow in the fullness of
time.  Questions are divided according to classes.

# GENERAL QUESTIONS

## Q. What is the RTFM system and how does it work?

**A.** The RTFM system is a system designed to get you to Read The Manuals.
   There are more than 100 sites running Amoeba and we have only two
   people available to do the research programming for Amoeba and to
   answer your questions.  The upshot is, we **cannot** deal with lots of
   questions and so we wrote some manuals.  We have no illusions about
   their completeness or correctness and are always willing to hear about
   errors, omissions (especially in the index) and inconsistencies.  We are
   also interested in hearing about bugs.  We don't want questions which are
   easily answered by reading the manuals.

   How it works is simple.  Every time you ask a question that was easily
   answered by reading the manual you score a point.  Every time you
   report a bug or error you lose a point.  If your total points exceed
   +4 you will get very slow response on new questions.  It is possible to
   get a negative point score - most of our beta-testers have very negative
   scores!

## Q.  What is the difference between a smallbullet (smbul) and bullet kernel?

**A.**  The smallbullet kernel uses a small buffer cache for the bullet server.
    It reserves 9 MB of memory for other programs like the name server and
    login.  It uses the rest of the free memory for its buffer cache.
    The (big) bullet kernel reserves only 5 MB and this is just enough for
    the name server and login.  A shell and other utilities won't fit in
    what is left over.

## Q.  What is the exact use of TCP/IP kernel?

**A.**  Its function is to convert between the TCP/IP network protocol and
    Amoeba's FLIP network protocol.  This way Amoeba processes can communicate
    with IP hosts such as UNIX machines.  In particular the RARP and TFTP
    daemons can run under Amoeba and boot machines like Suns which use TFTP
    to boot.

# UPGRADING

## Q.  How do I upgrade from Amoeba 5.2 to Amoeba 5.3?

**A.**  This is described in the release notes and the system administration guide.
    Together with the source code is a file `upgrade.tar.Z`.  This package
    contains a script to convert to the new directory graph layout.  It also
    contains a `README` file to tell you how to use it.
    It is a risky operation.  It may be better to see what the script tries
    to change and do it by hand if you have made any modifications to the
    directory graph structure.

# HARDWARE

## Q.  What hardware do I need to run Amoeba?
    
**A.**  This is described in the System Administration Guide.  However to be
    absolutely clear, you need at least 5 machines.  Less than that and it
    is not worth running Amoeba.  They don't all have to be of the same type.
    You can have 2 SPARCstations, 2 486 machines and 1 Sun 3/50.  They all
    need an Ethernet interface and at least one needs a disk (at least 200MB)
    and lots of memory (preferrably 16MB, except for Sun 3s which should have
    no more than 12 MB).

# System Specific Questions:

## ISA BUS MACHINES (ie. IBM PC clones)

### Q.  Are the NE2000 and NE2100 Ethernet cards (for ISA bus machines) compatible?

**A.**  No.  The NE2000 uses the DP8390 Ethernet chip and the NE2100 uses the
    AMD lance Ethernet chip.  The NE2100 chip has higher throughput than the
    NE2000 but it is only possible to put one in a machine due to its DMA
    (ab)use.  The NE2100 and its clones are somewhat scarce these days so the
    issue should become less important.  Furthermore both boards are supported.

### Q.  Is there a SCSI driver for the ISA port?

**A.**  Yes.  A driver for the Adaptec 1542 (A,B & C versions) is available.

## SPARC MACHINES (Sun4c & Sun4m and clones)

### Q.  Do I really need a tape drive to coldstart the SPARC port?

**A.**  Yes.  There are no plans to install from floppy.  If you have an existing
    Amoeba system then coldstarting (and therefore a tape unit) is not
    necessary.  You can simply install the binaries and kernels for the sparc
    on your existing system and boot them from there.

### Q.  Is there audio support for the Sun 4?

**A.**  No.

### Q.  Is there a FLIP driver for Solaris 2?

**A.**  Yes.  It works with Solaris 2.4 and newer.  At present it doesn't
    compile for the i86pc version of Solaris but we are working on it.

### Q.  Does Amoeba run on the MicroSPARC machines (SPARCclassic, LX, SS4, SS5)?

**A.**  Yes.

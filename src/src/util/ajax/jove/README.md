> [!NOTE]
>
>	README	1.1	92/05/13 10:22:30
>
> This program is Copyright :copyright: 1986, 1987, 1988 by Jonathan Payne.  JOVE
> is provided to you without charge, and with no warranty.  You may give
> away copies of JOVE, including sources, provided that this notice is
> included in all the files.

To make JOVE edit Makefile to set the right directories for the binaries,
on line documentation, the man pages, and the TMP files and select the
appropriate load command (see SEPFLAG in Makefile).  (IMPORTANT! read the
Makefile carefully.)  "tune.c" will be created from "tune.template" by
MAKE automatically, and it will use the directories you specified in the
Makefile.  (NOTE:  You should never edit tune.c directly because your
changes will be undone by the next make.  If you want to make a change to
a part of tune.c that isn't a directory name, you should edit
tune.template.)  Next you must edit "tune.h" selecting the compile time
options you care about.  See below for a description of all the compile
time options.  You can type "make" to compile XJOVE, PORTSRV (this is
compiled but not used on 4.2+ systems), RECOVER TEACHJOVE, and
MACVERT.  NOTE:  make won't work if it fires up /bin/csh for the shell
commands.  Test them out to see if they work.  If they do, type "make
install" to install everything where it belongs.

Here are some things to consider for deciding where to put the tmp files.
TMPDIR is where the tmp files get stored, usually /tmp or /tmp/jove.  If
your system does not remove subdirectories of /tmp on reboot (lots do
remove them these days) then it makes sense to make TMPDIR be /tmp/jove.
But if you want to recover buffers on system crashes, you should put the
lines
```
(echo preserving Jove files) >/dev/console
(cd /tmp; /usr/local/lib/jovelib/recover -syscrash) >/dev/console
```
in the /etc/rc file BEFORE /tmp is cleared, so that you can recover
files after reboots. There shoudl be a crontab entry to clear out
old files in /usr/preserve.

For the pdp11 version there is the Ovmakefile.  This has only been tested
on 2.9bsd.  It works pretty well, actually, and it is possible to turn on
all the compile time options with this version.

Bug reports:  If you find bugs in JOVE I would appreciate hearing about
them.  (My net address is at end of this message.)  So, send me the bug
reports.  If the bug isn't already fixed, I will ask you to send me the
fix.  If you haven't found the bug, I may be able to, so don't wait until
you have found it.  If you make improvements to JOVE and want them
incorporated into the official version, send me a message explaining what
the change is, and I will decide whether I want to include it.  If it is
possible for your change to be #ifdef'd in, that would be best, since I
want to avoid making JOVE huge.  For instance, if it's a new package type
thing (say, like word abbrev. mode, or something) then it would be best
if that were a compile-time option.  I will send out periodic updates to
comp.sources.unix.  I will report all significant bug fixes there, and to
net.emacs as well.

Here's a list of the compile time options and what they mean:

ABBREV	   - Enables word-abbrev-mode which again is nice for paper writers.

BACKUPFILES - This enables backing up files on write.  I guess lots of
	      people like this feature.  It enables the feature but you
	      can still control whether files are backed up with the
	      make-backup-files variable.

BIFF	   - This enables turning on and off BIFF so your screen doesn't
	      get messed up with messages from BIFF.

BSD4_2     - Obviously, if you're a Berkeley 4.2 system.

BSD4_3	   - If you're running a Berkeley 4.3 or 2.10 system.
	     This will automatically define BSD4_2, also.

CHDIR	   - This enables the directory commands; PUSHD, POPD, DIRS and
	      CD.  These simulate the csh commands exactly, I think.  As
	      a side-effect, absolute path names are enabled, which means
	      JOVE parses file names for "." and ".." and all that to get
	      at what you REALLY mean.  It's nicer when this is enabled,
	      but not essential.

CMT_FMT	   - This enables code to format and indent C comments.

ID_CHAR	   - Enables support for Insert/Delete character on terminals
	     that have those capabilities.  Couple of problems with this code:
	     it's large, takes up lots of I space which is a problem for the
	     smaller computers (pdp11).  Also, it isn't particularly smart
	     and sometimes does really stupid things.  It sometimes uses
	     insert/delete character when simply redrawing would have been
	     faster.  And if you look at code you'll understand why I don't
	     like it all that much.

IPROCS	   - Nice feature which lets you run interactive UNIX commands in
	     windows.  In particular, there is a shell command built
	     in which starts up an interactive shell in a window.  This works
	     only on systems with JOB_CONTROL since it relies on the fancy
	     signal mechanism.

JOB_CONTROL - Versions of UNIX that have the job control facility.
	      Berkeley 2.9-10 systems, and the 4.1-3 systems I know have
	      job stopping, so if you're one of those, define
	      this.  The reason MENLO_JCL is defined when JOB_CONTROL
	      is that the 2.9 signal.h file only defines all of the job
	      stopping signals only when MENLO_JCL is defined.

LISP	   - Enables Lisp Mode.  This includes code to indent "properly"
	     for Lisp code and new routines to move over s-expressions.
	     You probably won't want (or need) this on PDP-11's.

MY_MALLOC  - Use the older version of malloc that is more memory efficient
	     than the newer 4BSD version.  The 4BSD version places more
	     importance on the speed of the allocation than the amount of
	     memory it uses.  Make your	choice ... JOVE hardly ever calls
	     malloc, anyway, relatively speaking, since it allocates
	     lines in big chunks.  NOTE: This doesn't seem to work on suns
	     and the iAPX286.

PIPEPROCS  - If NOT defined, JOVE will use Berkeley pseudo-ttys when
	     doing interactive processes.  This is infinitely better,
	     since you get job control and all that stuff on i-procs.
	     If defined, the portsrv program will have to be made, and
	     all communication between jove and i-procs will be done using
	     pipes.

RESHAPING  - This is for BRL or Berkeley 4.3 and 2.10 systems.  When the
	     window size of the terminal jove is running in is changed
	     a SIGWINCH is sent to all processes in the tty group.  This
	     define enables code in jove to catch that signal and reshape
	     its windows.

SPELL	   - Enables the spell-buffer and parse-spelling-errors commands.
	     They are nice especially if you have lots of paper writers.

WIRED_TERMS - Include compiled-in hard-wired code for certain terminals,
	     like the Concept 100.  If you don't have these terminals,
	     you probably don't need this (but no point in taking it
	     out unless you're low on space).

The macros have been rewritten from scratch.  The most noteable change is
that they are no longer stored in binary files.  The write-macros-to-file
command writes a file which is suitable for use with the source command.
So you can have actual macro definitions in your .joverc if you want.  If
you have lots of macros defined in the old format, you can use the
macvert program to convert them to the new style.  You say
	macvert old-style-macros-file > new-style-macro-file

"doc/system.rc" and "doc/example.rc" are jove initialization files.
"system.rc" is the "system" rc file here at UoR, and it gets ready every
time JOVE starts up FOR EVERYONE.  ("make install" should copy the
system-wide .joverc to the right place automatically.)  After that JOVE
reads an initialization file in the user's home directory.  "example.rc"
is my personal .joverc.

The files "jove.[12345]" in DOC are the official JOVE manual.  I got
permission from Richard Stallman to use his manual for the original EMACS,
modifying it where necessary for JOVE.  Lots of work was done by Brian
Harvey on this manual.

There are man pages for jove and teachjove.  Teachjove is for people who
have never used EMACS style editors.  It is an interactive tutorial, THE
tutorial written by Stallman for the original EMACS, only slightly
modified for JOVE in the appropriate places.  The man pages are
completely up to date, thanks to me.

Thanks to Jay (hack) Fenlason for writing the original pty code.

Thanks to Dave Curry at Purdue for putting in tons of time and effort
into getting JOVE ready.  It just wouldn't be working without his help.

Thanks to Jeff Mc Carrell at Berkeley for finding bugs and adding
features, in particular, the comment formatter.

Thanks to Karl Gegenfurtner for making the PC version.

Thanks to Ken Mitchum for the Macintosh verison.

Thanks to Hugh Redelmeier for his input, his experience, countless bug
fixes, and ... that's it, I guess.

(Thanks to Brian Harvey for teaching me about linked lists ...)

Good luck, have fun.

	Jonathan Payne (jpayne@sun.com until further notice :-)

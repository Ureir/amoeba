> [!NOTE]
>
>	Readme.dos	1.1	92/05/13 10:22:41
>
> This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE
> is provided to you without charge, and with no warranty.  You may give
> away copies of JOVE, including sources, provided that this notice is
> included in all the files.

# HOW TO GET STARTED WITH JOVE:

You can immediately start using Jove if you have an IBMPC
compatible PC, XT or AT. You can fine tune some things by setting
certain environment variables, but it's not really necessary
If your computer is not IBM BIOS compatible, you have to set some
environment variables before starting Jove.
What follows is a description of those variables.

# ENVIRONMENT VARIABLES USED BY JOVE:

## TMP (or TMPDIR)
Jove uses the value of TMP to determine the directory where it should
put its temporary file. The default is the current directory, and this
is probably not what you want. In general editing is faster, if TMP
points to a ramdisk, like "set tmp=d:". You have to know however that
the temporary file can grow quite big when editing many big files at
once. So please make sure that you have enough space available on your
ramdisk. If Jove runs out of space on the device which holds the
temporary file, you have to leave the editor immediately. You can save
your work without any trouble, but you have to start over. Please note
also that the current version of Jove has a big cache for the
temporary file in memory, which makes it quite fast even if you don't
have a ramdisk.

## DESCRIBE
This variable tells Jove, where it can find the file that holds the
online documentation. You should set DESCRIBE to the complete
path-specification of the file "cmds.doc", which is included as part
of the documentation. The default for DESCRIBE is "c:/unix/cmds.doc".

## JOVERC
This is the complete path for Jove's startup file. All commands in the
file, that JOVERC points to, are executed every time when you run
Jove. If there is a file called "jove.rc" in the current directory,
then it is also "sourced", ie. the commands in that file are executed.
That way you can customize Jove to your own taste.

The next two variables are not used by the IBMPC version, and have to
do with specifying the type of terminal in use on a generic msdos
computer.

## TERM
This variable should specify the name of the terminal you are using.
For example, if you have a DEC vt-100 terminal attached to your msdos
computer, you should give the command "set TERM=vt100" prior to
starting Jove.

## TERMCAP
This environment variable holds the name of a database with
descriptions of different terminal types. If you are familiar with the
Unix operating system, you probably know about TERMCAP. For each
terminal type, specified by TERM, the TERMCAP database holds an entry,
which describes how to set the cursor, how to scroll, and many other
things, for that particular terminal. A small example TERMCAP file
comes with Jove. If your terminal is not included there, you should ask a
local Unix guru for help. If you don't have one, you can ask me.

## METAKEY
Some kinds of terminals have a special shift key that Jove can recognize,
the so called MetaKey. When the environment variable METAKEY is set, Jove
assumes that you have such a terminal, and treats the codes that your
terminal sends in a slightly different way. Pressing down the MetaKey
and another key at the same time is a then a shorthand for pressing
first the "esc" key, and then the other key.


## DIFFERENT VERSIONS OF JOVE:

The text above already indicated that Jove comes in different versions
for different types of computers. Not only that, there also exist
versions that differ in the way they use the memory of the computer.

The "large" versions of Jove use all the memory available if it is
necessary. The temporary file can grow infinitely large in those
versions. The number of lines that can be edited with the large
version is about 20000 to 25000 on a PC with 640 kB of memory. Note
that there is no limit on the size of the file itself.
The "medium" versions of Jove are more conservative in their use of
memory. They always take up about 130 kB of memory, which leaves a big
rest for executing large programs, like the C-Compiler from within
Jove. The size of the temporary file is also limited to 512 kB in the
medium versions. The leads to a limit of approximately 4500 to 5000
lines that can be edited at one time.
The standard executable files that are distributed in binary form, are
usually the large ones. If you need a medium version, you either have
to recompile Jove from the sources (see below), or you can get get
it from someone else who has compiled it, for example from me.

There currently exist versions of Jove for three different types of
msdos computers. PCJOVE is for IBMPC compatible computers. Compatible
means here that the ROM Bios of your computer has to support the same
Video output calls as the PC's. So even if your "clone" has trouble
with many other programs, there's a high chance that Jove will work.
MSJOVE should generally run on any computer that runs the msdos
operating system. It strictly uses only well documented system calls
to do its task. RBJOVE is a special version of MSJOVE for DEC Rainbow
computers, which uses the Rainbows Bios for screen output and keyboard
input. This makes it much faster than MSJOVE on the Rainbow.


# DIFFERENCES BETWEEN JOVE UNDER MSDOS AND UNIX JOVE:

The msdos version of Jove currently supports all of the features that
are possible to implement under msdos in a reasonable way.
Version 4.8b in particular supports:
-	filename completion
-	comment filling
-	creation of backup files
-	word abbreviation mode
-	Lisp mode
-	change directory within Jove
-	executing commands from within Jove
-	filtering regions through msdos commands

You have to look into the manual for more explanations of these
features. The things that are missing under msdos are:
-	spell-buffer (obsolete under msdos)
-	interactive shells in a window (not possible)

There are however some features added, which are specific to the PC
version.

## Variables:
- `Background-color` specifies the background color of the screen. The default
  value is 0, which stands for black.
- `Foreground-color` specifies the foreground color of the screen. The default
  is 1, which stands for white. The attribute used for writing to the
  screen is formed by (bg&7)<<4 & (fg&7).
- `Mode-line-color` specifies the color of the modeline. Its default
  value is 0, and in that case it is drawn in reverse video. If it has
  any other value, this value is used as the attribute in Bios calls.

(note that on a monochrome monitor the best thing is to leave the
default colors - anything else can lead to blank screens very easily)

## Commands:
- `Scroll-previous-page` continuously scrolls down screen-full lines.
- `Scroll-next-page` continuously scrolls up screen-full lines.
- `Select-buffer-n`, where n is in the range 0 to 9, selects buffer n as the
  working buffer. These commands are bound to the <alt>[0-9] keys by
  default. For example, pressing the alt key and 3 at the same time
  switches immediately to buffer 3.

## General:

PCJOVE supports the whole 8 bit character set of the IBMPC. You can
use all the line drawing characters in your files. It also knows
about some special foreign characters (Umlaute), which are treated
correctly as part of words and in case conversions.

# VIDEO MODES ON THE IBMPC:

This concerns PCJOVE only. When Jove is started, it automatically
checks which video mode is currently used, and adjusts itself
correspondingly. This means that Jove will work correctly even in
40x25 mode. If you have an Ega card, and want to use the special mode
with 43 lines, set the environment variable TERM to the value EGA, or
set the variable EGA to any value. This will tell Jove to set the
screen in 80x43 mode. The regular 80x25 mode is restored upon exit.
On a color monitor, you can change the screen colors by using the
commands mentioned above.

There is a problem in using Jove together with Hershey
MicroComputing's FansiConsole screen driver. FansiConsole doesn't
properly set some of the values in the Bios control area. This usually
leads to a crash when Jove starts. You can restore the information
Jove needs by giving the command "mode co80" before starting Jove.
Note that Kermit version 2.30 has the same problem, and that it can
only be fixed by fixing FansiConsole.

# COMPILING JOVE UNDER MSDOS:

Jove can currently only be compiled with the Version 5.0 of the
Microsoft C Compiler. Jove uses some library function calls that were
not included with version 4.0 or earlier of Microsoft C. The `makefile`
that is included with the sources will not work with Microsofts lousy
make. I recommend that you use `ndmake`, a public domain (or is it
shareware) make utility, which is much better than Microsofts.
Jove can be compiled with the medium, or the large memory model. To
get the IBMPC version, the option `-DIBMPC` should be given at the
command line for the Compiler. Similarly, the define for the Rainbow
version is `RAINBOW`. The variable `MSDOS` is always defined by the
compiler. If you want to disable some features you can do so by making
changes to `tune.h`.

If you want to give away the version of Jove you are compiling to
other people, don't use the loop optimizations or intrinsic
functions!!! The compiler currently has some bugs in the optimizer,
which causes it to produce wrong code sometimes, and in unpredictable
places. Look at the function **DoJustify()**, in `paragraph.c`, for an
example. Note that the `#pragma` is commented out because compilers on
other machines don't like it. If you find that the version you just
compiled behaves strange in some way, and you compiled with
optimizations on, check whether it works ok with optimizations
disabled before you tell all the world about a new bug in Jove.
If you want to compile `MSJOVE` or `RBJOVE`, you need the library `MTERMLIB`
or `LTERMLIB`, for medium or large memory model, respectively. These
libraries contain the functions for dealing with the termcap database.

If you want to compile Jove with Turbo-C, the port has already been
done by Brian Campbell (brianc@cognos.uucp). A separate file with the
diffs is currently available from him, and will probably be included
as ifdefs in future versions.

If you find a bug in Jove, have some questions, or some suggestions,
you are always welcome. Just send mail to me. My address is:

          Karl Gegenfurtner

arpa:     karl@hipl.psych.nyu.edu
uucp      {ihnp4|seismo|allegra}!cmcl2!xp!hipl!karl
usps:     New York University
          Dept. of Psychology
          6 Washington Place 8th floor
          New York, NY 10003

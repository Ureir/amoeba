> [!NOTE]
>
>	Readme.mac	1.1	92/05/13 10:22:52
>
> This program is Copyright :copyright: 1986, 1987, 1988 by Jonathan Payne.  JOVE
> is provided to you without charge, and with no warranty.  You may give
> away copies of JOVE, including sources, provided that this notice is
> included in all the files.

## Changes between 4.9 and 4.10:

New features:
1. Reshapeable windows with zoom boxes.
2. Filename/directory name completion with macify OFF.
3. Double click mouse to set the mark.
4. Control-space and control-@ correctly send NUL on MacII/SE.
5. Control-\` fixed to send backquote char.
6. Display update code fixed.

Sources:
1. Compiles under LSC 3.0. (Probably under 2.13 as well, but
   not tested with that version).
2. Include files redone, with fewer total lines of code.
3. No need to modify include files, unless NBUF changed.
4. "keymaps.txt" is now "keys.txt".

Planned:
1. Recover command as separate application.
2. Support for MPW compiler vers 2.02.

## Introduction

This file contains a brief description of MacJove, along with
information necessary to make MacJove from the source files.
It is assumed that the reader is familiar with Jove from other
systems, and is somewhat familiar with the Macintosh as well. In
the future there may be a separate user's manual for MacJove:
for the time being, the reader should refer to the Jove manual
for Unix users.

## Description

MacJove is a direct port of Jove to the Macintosh, with the
overall structure, commands and key bindings left intact. In
addition, elements of the Macintosh user interface - menus,
window controls, and the mouse, have been integrated in a manner
consistent with the overall functioning of Jove.

While the integration of these tools into the Jove environment
is consistent and, to most users, familiar, Jove departs in
several places from "Macintosh User Interface Guidelines". Most
notably, the mouse is used to position the point only, not to
drag or select text, and the Jove buffer structure is not
integrated with the clipboard. Also, key bindings conform to
Jove/Emacs tradition, and not to Macintosh guidelines: i.e.
control (command)-N is next-line, not "NewFile". The reason for
these departures is that the majority of MacJove users are likely
to be those already familiar with Jove or other Emacs editors
on other systems, and for these users, consistency between machines
and operating systems is more important than fully exploiting
the features of a single system. There are numerous other text
editors which fully follow the Macintosh User Interface Guidelines.

MacJove retains most features of other Joves, but certain commands
cannot be implemented because of the Macintosh operating system.
Thus, there is no way to run a sub-process or a shell in a window,
because there are no shells to run on the Macintosh, and a program
(currently) can only transfer control to another program, not run
a child process. For similar reasons, commands dealing with mail,
with running make, and checking errors, are omitted.

# Running MacJove

## System Requirements

MacJove should run without difficulty on any Macintosh Plus, SE, or
Macintosh II, providing that the hierarchical file system (HFS) is used, and
assuming a reasonably current system file is used. An upgraded 512K Mac
(with 128K rom) should also work if there is enough memory.  MacJove was
developed on a Macintosh Plus and Macintosh II running system 4.2 and Finder
6.0., and has not been fully tested on earlier systems - however, it is
likely that it will run on system 3.2 and later versions. MacJove has been
used to a limited extent with Switcher and under Multifinder. In both cases,
it is important to reserve enough memory for MacJove, as discussed below.

MacJove, as compiled from the sources, uses memory as follows:
```
   Program Code     approx 116K
   Static Data      approx  20K
   Tempfile Cache           64K (heap)
                           ____
                           200K total before stack/heap considerations
```

To this must be added stack and heap space. A bare minimum for this is
probably 100K or so, but the usage will vary as buffers are created.  With
Jove, the file itself takes up space only in the tempfile and its cache, but
the buffer structure requires 3 pointers (12 bytes) for each line in the
file. For a reasonable editing session with files totalling, say 10000 to
20000 lines, this additional space can add up. For this reason, it is
unrealistic to expect to run Jove on a 512K system, unless a very small
system file is used, few, small files are edited each session, and the
tempfile cache is reduced (see cache size under Making Jove). You can
experiment with various memory allocations under Switcher and Multifinder to
see what works with your editing habits (backup your files first!), but a
realistic minimum is 400K - 500K and more is great.

When first using MacJove, and if memory space is questionable, SAVE YOUR
FILES FREQUENTLY. If it is necessary to edit many files, it is often better
to exit MacJove and restart once in a while, especially if there is a
question of limited memory.

## Operation

Running MacJove is similar to other Macintosh applications, and should be
intuitive. You start up MacJove by either opening, or double-clicking,
the MacJove icon. If you have previously saved files created with MacJove,
double-clicking on them will also start up the program, and the files will
be put into buffers. Several files can be selected simultaneously by this
method. There is no current way to select command-line options with
MacJove, but this may change in the future.

The .joverc file, if used, must be present in the same directory as MacJove,
the "home" directory. The help file, "cmds.doc", must also be in this
directory. The tempfile, ".joveXXX", will be placed in whatever directory is
current when the tempfile is first opened - this may or may not be the home
directory, and may change in the future. The recover file, ".jrecXXX" is
placed in the home directory. While this file is created and updated as on
Unix versions of Jove, there is currently no "recover" program for MacJove.
Hopefully, this will be available soon.

MacJove can edit any text file on the Macintosh, whether created with
MacJove or another editor. It cannot be used to edit graphics material, and
graphics material cannot be inserted during operation of MacJove. Files
created with MacJove are of type 'TEXT' and of signature 'JV01'. This
signature is being registered with Apple, and may change if necessary. Note
that once MacJove files have been re-edited with another editor, they likely
will have new signatures, and double-clicking on them will start the other
editor, not MacJove.

The standard Macintosh keyboard is inadequate for MacJove (and most anything
else), so that it is necessary to change a couple of keys. The "\`" key
becomes the ESCAPE key, since it is in the right place for one: to send a
real "'", hold the command key down while typing it. The command key is used
for a control key - unfortunately, the location of it is horrible for such a
purpose. On Macintosh SE and Macintosh II models, a real escape key exists,
and also a real control key. Note, however, that because of a small bug in
the keyboard encoding in MacJove, you cannot directly send a NUL (control-@)
with the control key. Typing command-@ or command-2 will still do this,
however.

During operation, you can use the keyboard as you would when running Jove on
any other system. However, many commands also have menu equivalents:  as
long as MacJove is waiting for a command, you can use either the keyboard or
the menus. Once you begin selecting a command with either the menus or the
keyboard, the other is locked out: thus, once you type control-X, MacJove
expects more characters, and will not let you choose menu items.  Also, if
you are prompted for input on the command line, the menus are locked out.
Regardless of how a command is begun, however, only the prompt line (message
line) is used for input: MacJove does not use dialog boxes, except under the
"About Jove" menu selection.

Commands listed in the menus are given exactly as their string name in
the command list, for example "write-file". In addition, variables are
listed under the "Set" menu. Variables are grouped by type. Non-boolean
variables are changed on the message line after being selected. Boolean
variables are marked with a check mark if on, and selecting them toggles
the value of the variable.

The "Buffer" menu is a special menu, whose action is different than the
others. The first entries on this menu are the major and minor modes of
operation, with those of the current buffer marked with check marks.
Clicking on a major mode will change the major mode of the current buffer to
that mode, while clicking on a minor mode will toggle that mode's status
(on/off) for the current buffer. Beneath this is a list of buffers, one for
each menu item, with the current buffer marked. Clicking on a buffer selects
that as the current buffer, and the active window will change accordingly.

Window controls (scroll bars) work as expected, and are simply bound to
the appropriate MacJove command. Occassionally the position of the
scroll bar may appear inaccurate, particularly with a small buffer.

Files and directories may be selected in two ways. The default method
is to use the message line to input filenames, and to change directories
using "cd". If the variable "macify" is set, however, filenames and
directories can also be set using the standard file dialogs familiar to
most Mac users. Filename paths are normally given via Unix conventions,
and not Macintosh conventions: i.e. directories are separated with "/"
and not ":". On the Buffer menu, however, filenames are listed with ":"
as the separation character, since "/" cannot be displayed in menu items.
It is not possible to back up directories beyond the volume level, so
there is not true "root". To change volumes (disks), macify must be on,
and the "Drive" selection used.

"Macify" only works for those commands which REQUIRE a file operation, such
as "visit-file", "insert-file", "write-file".  Operations which first look
in buffers for files, such as "window-find" and "find-file" never use the
standard file dialogs.

For a list of all commands and bindings, click on "About Jove" in the
Apple menu. In the future this may also support the help file.

# Making MacJove

## System Requirements

To make MacJove from the sources, you need a hard disk based Macintosh, at
least 1 mb of ram, and the LightspeedC compiler, version 2.13 or later.
Earlier versions may work but have not been used recently. Allow for the
MacJove files to take up to 1.5 mb of your hard disk. You will need a copy
of the "BinHex" utility, also.

Since LightspeedC does not work with a Makefile, none is supplied. In
general, the compiler itself will figure out dependencies for you, within a
"project". Since there are three separate projects to MacJove, you will
still have to keep track of some changes, particularly for the setmaps
project. Also, since LightspeedC only knows of .c and .h dependencies,
you will have to keep track of setmaps.txt and menumaps.txt yourself.

## Preliminary Steps

0. CREATE A FOLDER (DIRECTORY) FOR JOVE. If I have to tell you how to do
that, don't go any further! Copy the source files - a few aren't needed
by MacJove, but copy them anyway, so you'll have them in one place. You
do not need anything in the "doc" subdirectory to create MacJove (but
you will eventually need cmds.doc, the help file, if you want the
"describe-command" command to work).

1. CREATE THE RESOURCE FILE: There is only one eight-bit file supplied,
"mjove.rsrc". This is a small file which contains the program icon and a
dialog template. This file must have the same name as the MacJove project,
plus extension ".rsrc". The MacJove project (below), has name "mjove", so
this file is "mjove.rsrc".  IF YOU RENAME THE PROJECT YOU MUST RENAME THIS
FILE, ALSO. Using "BinHex", unload the file "mjovers.Hqx" --> "mjove.rsrc".

2. CREATE THE "MJOVELIB" PROJECT: MacJove does not use many of the library
functions. Despite what the LightspeedC manual states, projects are loaded
as a whole: since we need only a few functions, we will build a "library" of
them in the form of a project. Run LightspeedC and create a new project,
and name it "mjovelib". Add the following files, from the Library Sources,
to the project. They all go in the same segment:
```
     onexit.c
     qsort.c
     stddata_ctype.c
     unixexit.c
     unixid.c
     unixmem.c
     unixtime.c
```

3. EXAMINE THE FILE UNIXTIME.C and make the following correction, if
necessary. The LightspeedC library function "unixtime.c" returns a string
containing the time for what is supposed to be Greenwich Mean Time, instead
of local time. Using the LightspeedC editor, and with the project open,
examine the file, comment out the definition of "GMTzonedif", and add:
```
     #define GMTzonedif 0
```

4. MAKE THE "MJOVELIB" PROJECT. Keeping the edited "unixtime.c" open,
run "make" on the project - everything will be compiled, with the altered
version of "unixtime.c". You do not have to permanently save the change
to unixtime.c, but if you do not, the next time you run "make" on the
project, it will tell you that it needs recompiling - simply ignore it.
After the mjovelib project is made, close it. You do not have to convert it
to a library - it is okay to leave it as a project.

6. CREATE THE "MSETMAPS" PROJECT. Create a new project, name it "msetmaps",
and add the following files to it:
```
     setmaps.c
     stdio
     strings           (segment 1)
     unix
     unix main.c
     --------
     MacTraps          (segment 2)
```

You should not change anything else at this point - unless you want to
reduce memory requirements (see "Running MacJove", above). If it is
necessary to reduce the memory requirements, then reduce the number of cache
buffers, NBUF, which is defined near the end of the file (each buffer takes
up 1K of space while MacJove is running).
```
#ifdef MAC
# undef F_COMPLETION
# define F_COMPLETION 1
# define rindex strrchr
# define bzero(s,n) setmem(s,n,0)
# define swritef sprintf
# define LINT_ARGS 1
# define NBUF 64 <---- here
# define BUFSIZ 1024
# undef LISP
# define LISP 1
# define ANSICODES 0
# undef ABBREV
# define ABBREV 1
# undef CMT_FMT
# define CMT_FMT 1
#endif
```

7. MAKE THE "MSETMAPS" PROJECT. Then choose "Build Application",and name it
"setmaps".

8. RUN "SETMAPS" ON THE KEYMAPS.TXT FILE. You can either run "setmaps" from
LightspeedC, before closing the project, or as the standalone application.
When prompted for the "Unix command line", enter:
```
     < keys.txt > keys.c
```

You will get a few messages from setmaps that it can't find certain
commands. You can ignore these.

9. RUN "SETMAPS" ON THE MENUMAPS.TXT FILE. Just as before, run "setmaps"
and enter the following command line:
```
     < menumaps.txt > menumaps.c
```
You should not get any messages from setmaps. If the "msetmaps" project is
still open, close it.

10. CREATE THE "MJOVE" PROJECT. Create a new project, name it "MJOVE" and
set the Creator (signature) to 'JV01'. Add the following files in the
following segments:
```
     abbrev.c
     argcount.c
     ask.c
     buf.c
     c.c
     case.c        (segment 1)
     ctype.c
     delete.c
     disp.c
     extend.c
     keys.c
     --------
     fmt.c
     fp.c
     funcdefs.c    (segment 2)
     insert.c
     io.c
     jove.c
     keymaps.c
     list.c
     --------
     mac.c
     macros.c
     marks.c
     menumaps.c    (segment 3)
     misc.c
     move.c
     paragraph.c
     --------
     re.c
     re1.c
     rec.c
     screen.c
     term.c       (segment 4)
     util.c
     vars.c
     version.c
     wind.c
     --------
     MacTraps
     mjovelib
     setjmp.Lib    (segment 5)
     storage
     strings
```

11. MAKE THE MJOVE PROJECT. If you experience any errors, it will most
likely be from #include files not being in the default path - see the
LightspeedC manual on setting up your directories. When you are done,
run the program from the compiler to verify that it is okay, then save it as
"MacJove" using the "Build Application" command.

12. (Optional) CREATE THE HELP FILE, "CMDS.DOC". If you do not have a copy
of "cmds.doc", it must be created using nroff. Assuming you have the Jove
sources on a Unix machine, run "Make doc/cmds.doc" to create this file in
the "doc" subdirectory, then move the file to the Mac. If you obtained the
sources from a non-Unix source, this file may already be supplied. Place the
file in the same directory that MacJove will be in.

# COMMENTS AND QUESTIONS, BUGS

Although Jove appears to work well on the Mac, I know there are some
problems. Since Jove cannot effectively use the TextEdit routines, it
does not comply with some aspects of the Macintosh User Interface
Guidelines. As has recently been brought to my attention, Jove accesses
files by pathname only, so that if you have two disks in your machine
with the same volume (disk) name, it will become confused. This has not
been fixed. Support for variant keyboards is not good at present.

I try to reply to all inquiries about MacJove, but my schedule is busy,
and it may be several days before you hear from me on the net. Please
reply via email to me, or through usenet if possible: the chances that
I will respond quickly to a written question or suggestion are very
small, and I am difficult to reach by phone. Please do NOT send disks
unless I ask you to.

    Ken Mitchum
    Decision Systems Laboratory
    University of Pittsburgh
    1360 Scaife Hall
    Pittsburgh, Pa. 15261

    (km@cadre.dsl.pittsburgh.edu)

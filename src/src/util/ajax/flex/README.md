> [!NOTE]
>
>	README	1.1	91/04/11 16:47:00
>

This is the initial release of **flex**, a replacement for the **lex**(1)
tool.  As the copyright indicates, this distribution can be freely
redistributed.

Some notes on the distribution:

    Yes, there are some niggling **lex** features which are not available which
    seem like they'd be easy to add.  They're not, or if they are then the
    straight-forward implementation of them would slow down the scanner.
    Unfortunately I am unable to do any further work on **flex** other than bug
    fixes, so if there's something you've just gotta have, you'd better
    be willing to dive into the code.  I'll be happy to give (fairly
    high-level) advice on how to proceed.

    The compressed tables have been tested pretty thoroughly in the past,
    though may be suffering from bit-rot.  The fast/full tables have been
    recently implemented and are more likely to have bugs.

    For a System V machine, add the `#define SV`.  Not guaranteed to do
    the full job, but a step in the right direction.

    Flex has been successfully ported to Sun Unix and 4.3BSD Vax Unix.


The **flex** distribution consists of the following files:

```
	README		This message

	Changes		Differences between this release and the beta-test

	Makefile
	flexdef.h
	parse.y
	scan.l
	ccl.c
	dfa.c		flex sources
	ecs.c
	main.c
	misc.c
	nfa.c
	sym.c
	tblcmp.c
	yylex.c

	scan.c.dist	pre-flex'd version of scan.l

	flex.skel
	flex.fastskel
	flexskelcom.h	skeleton scanner sources
	flexskeldef.h
	fastskeldef.h

	flex.1		manual entry

	Timings		a brief note comparing timings of flex vs. lex
```

Either move {`flexskelcom.h`,`flexskeldef.h`,`fastskeldef.h`} into `/usr/include`
or edit {`flex.skel`,`flex.fastskel`,`flexskeldef.h`,`fastskeldef.h`,`scan.c.dist`}
and wire in the full pathname of where you are going to keep the include files.

Decide where you want to keep {`flex.skel`,`flex.fastskel`} (suggestion:
`/usr/local/lib`) and move it there.  Edit `Makefile` and change the
definitions of `SKELETON_FILE` and `F_SKELETON_FILE` to reflect the full
pathnames of {`flex.skel`,`flex.fastskel`}.

To make flex for the first time, use:
```
    make first_flex
```
which uses a pre-generated copy of the scanner whose source is in flex.

Assuming it builds successfully, you can test it using
```
    make test
```
The "diff" should not show any differences.

If you're feeling adventurous, rebuild `scan.c` using various
combinations of `FLEX_FLAGS`, each time trying `make test` when
you're done.  To rebuild it, do
```
	rm scan.c
	make FLEX_FLAGS="..."
```
where "..." is one of:
```
	-ist -c
	-ist -ce
	-ist -cm
	-ist -cfe
	-ist -cFe
```
and testing using:
```
	make FLEX_FLAGS="..." test
```

Format the manual entry using
```
    nroff -man flex.1
```

Please send problems and feedback to:
	vern@lbl-{csam,rtsg}.arpa  or  ucbvax!lbl-csam.arpa!vern

	Vern Paxson
	Real Time Systems Group
	Bldg. 46A
	Lawrence Berkeley Laboratory
	1 Cyclotron Rd.
	Berkeley, CA 94720

	(415) 486-6411

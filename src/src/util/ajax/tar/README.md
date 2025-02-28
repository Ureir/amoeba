> [!NOTE]
>	
>	README	1.1	91/04/12 14:47:53
>

This is the Nov87 release of a public domain **tar**(1) replacement.  It
implements the `c`, `x`, and `t` commands of Unix **tar**, and many of the
options.  It creates P1003 "Unix Standard" \[draft 6\] tapes by default,
and can read and write both old and new formats.  It can compress or
decompress tar archives "on the fly" (using the `z` option) as well as
accessing remote tape drives or files by specifying
`host:/dev/tapedrive`.  It lets you set the default tape drive by
setting TAPE in your environment.  Its verbose output looks more like
`ls -l` than the Unix **tar**, the columns line up, and you can get verbose
listings from the `cvv` option as well as from `xvv` and `tv`.  It does
shell-globbing (regular expressions) for listing and extraction.  It is
a little better at reading damaged tapes than Unix **tar**.  There is a
half-baked "diff" option for comparing a tape against the file system.
And it's free.

It is designed to be a lot more efficient than the standard Unix **tar**;
it does as little bcopy-ing as possible, and does file I/O in large
blocks.  On the other hand, it has not been timed or performance-tuned;
it's just *designed* to be faster.

On SunOS 3.3, the tar archives it creates under the 'old' option are
byte-for-byte the same as those created by /bin/tar, except the trash
at the end of each file and at the end of the archive has been replaced
by zeroes.

It was written and initially debugged on a Sun Workstation running
4.2BSD.  It has been run on Xenix, Unisoft, Vax 4.2BSD, utzoonix, USG,
Masscomp, Minix, and MSDOS systems.  I'm interested in finding people
who will port it to other types of (Unix and non-Unix) systems, use it,
and send back the changes; and people who will add the obscure tar
options that they happen to use and I don't.  In particular, VMS, Mac,
Atari and Amiga versions would be handy.

It still has a number of loose ends, marked by "FIXME" comments in the
source.  Fixes to these things are also welcome.

I am the author of all the code in this program, except some of the
subroutines, which are from contributors listed below.  I hereby place
it in the public domain.  If you modify it, or port it to another
system, please send me back a copy, so I can keep a master source.

This program is much better than it started, due to the effort and care
put in by Henry Spencer, Fred Fish, Ian Darwin, Geoff Collyer, Stan
Barber, Guy Harris, Dave Brower, Richard Todd, Michael Rendell, Stu
Heiss, and Rich $alz.  Thank you, one and all.

	John Gilmore
	Nebula Consultants
	PO Box 170608
	San Francisco, California, USA  94117-0608
	hoptoad!gnu    or   gnu@toad.com
	Hoptoad talks to sun, ptsfa, ihnp4, utzoo, ucsfcgl.

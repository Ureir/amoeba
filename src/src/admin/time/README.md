> [!NOTE]
> README	7.1
>	
>	README	1.1	91/04/02 15:08:26
>

"What time is it?" -- Richard Deacon as The King

"Any time you want it to be." -- Frank Baxter as The Scientist
					(from the Bell System film on time)

This 1989 update of the time zone package features

-	POSIXization (including interpretation of POSIX-style TZ environment
	variables, provided by Guy Harris),
-	ANSIfication (including versions of "mktime" and "difftime"),
-	SVIDulation (an "altzone" variable)
-	MACHination (the "gtime" function)
-	corrections to some time zone data (including corrections to the rules
	for Great Britain and New Zealand)
-	reference data from the United States Naval Observatory for folks who
	want to do additional time zones
-	and the 1989 data for Saudi Arabia.

(Since this code will be treated as "part of the implementation" in some places
and as "part of the application" in others, there's no good way to name
functions, such as timegm, that are not part of the proposed ANSI C standard;
such functions have kept their old, underscore-free names in this update.)

Support for the tz_abbr variable has been eliminated from this version
(to forestall "kitchen sink" complaints from certain quarters :-).

Support for Turbo C compilation has also been eliminated; it was present to
allow checking in an ANSI-style environment, and such checking is now done with
gcc.

And the "dysize" function has disappeared; it was present to allow compilation
of the "date" command on old BSD systems, and a version of "date" is now
provided in the package.  The "date" command is not created when you "make all"
since it may lack options provided by the version distributed with your
operating system, or may not interact with the system in the same way the
native version does.

Since POSIX frowns on correct leap second handling, the default behavior of
the `zic` command (in the absence of a `-L` option) has been changed to omit
leap second information from its output files.

Please send comments or information to ado@ncifcrf.gov.

Be sure to read the comments in `Makefile` and make any changes
needed to make things right for your system.

To use the new functions, use a `-lz` option when compiling or linking.

Historical local time information has been included here not because it
is particularly useful, but rather to:

-	give an idea of the variety of local time rules that have
	existed in the past and thus an idea of the variety that may be
	expected in the future;

-	provide a test of the generality of the local time rule description
	system.

The information in the time zone data files is by no means authoritative;
if you know that the rules are different from those in a file, by all means
feel free to change file (and please send the changed version to
ado@ncifcrf.gov for use in the future).  Europeans take note!

Thanks to these Timezone Caballeros who've made major contributions to the
time conversion package:  Keith Bostic; Bob Devine; Robert Elz; Guy Harris;
Mark Horton; John Mackin; and Bradley White.  Thanks also to Michael Bloom,
Art Neilson, Stephen Prince, John Sovereign, and Frank Wales for testing work.
None of them are responsible for remaining errors.

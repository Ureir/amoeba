> [!NOTE]
> Copyright :copyright: 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.4	94/04/07 14:45:56
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

# Make

To compile Amake with Make, copy the file Makefile to the configuration
directory in which the compilations should take place.
The Makefile contains some configuration flags which have to be set
according to the local situation, such as paths (e.g., AMAKELIBDIR), OS, etc.
You will also have to set the variable AMAKE\_SRC\_DIR to the pathname
of the directory containing the sources (i.e., this directory).

Calling "make" without parameters should result in the executable "amake".
Before you install it, it is probably wise to test it first; a nice testcase
is to compile Amake with Amake (see next item).

# Amake

If you have made a version of Amake, you should also try to let Amake compile
itself. To do this, rename amake to, say XXamake in this configuration
directory and run it.  If all goes well, this will give a binary "Amake"
(notice the capital A).
Amake is link()ed to a file in the .Amake/version00 directory, so when you
install it, be careful to copy (rather than move) it.


Please send bug reports (with example and version number), fixes, complaints,
etc. to amake@cs.vu.nl

Good luck.

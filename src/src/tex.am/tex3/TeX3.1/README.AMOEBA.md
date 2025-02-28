> [!NOTE]
>	
>	README.AMOEBA	1.1	91/11/21 14:16:40
>
This describes changes I made to the make and installation to get TeX running
on amoeba.

1. First note that some TeX utilities, like `tangle` and `weave`, are used in 
building the rest of TeX.  These utilities I've made only to run on Unix.  They
are not to be installed on amoeba.  The makefiles can be altered to generate
versions for amoeba, but there seems to be no point in doing this.

2. There is a directory called `common`, which is to contain common object files,
used in creating the various TeX utilities.  Because some of the utilities run
on amoeba and some on Unix, I have created an `amcommon` directory, which will
contain object files used in making the amoeba-bound utilities; as before, the
`common` directory applies to Unix-bound utilites.

3. In the TeX3.1 directory is the top-level makefile.  This makefile passes make
args on to the Makefiles in the various subdirectories.  Where only the variable
`makeargs` existed before, I have now created `makeargs` and `makeargslite`.  `makeargs`
is passed to the Makefiles which build the amoeba routines.  `makeargslite` is
passed to the Makefiles which build the Unix routines.

4. The README file contains directions for building big TeX and small TeX.  Small
TeX will run on any amoeba processor, but big TeX needs between 3 and 4 Mb and is
destined to run on the machine `ast`.  The README file states that the glueratio in
`site.h` has to be altered.  In addition, files in the three directories, `tex`, `mf`, and
`bibtex`, have to be renamed.  Since there may be interest in switching back and
forth between the two sizes, I have automated this process.  There is a new variable
in the top-level makefile.  `SIZE=32` for big TeX and `SIZE=16` for small TeX.  There
is no longer a need to touch the glueratio in `site.h`.  Also, if the `.ch` files in
tex, bibtex, and mf are named to be `*16.ch` and `*32.ch`, rather than `*16.ch` and `*.ch`,
then the `SIZE` variable can be used to pick up the proper file automatically.  
These changes have already been made in the conf directory.

5. The makefile has also been changed so that `make install` installs the executables
and other files on amoeba from Unix.

6. Note also that `xdvi` has been built for amoeba.  One thing that must be done by
hand for now is the moving of the various TeX rastered fonts over to amoeba.
These fonts will ultimately reside in the /public/module/tex/fonts/raster directory.
`xdvi` needs these fonts to run.

7. See the `README` file in the TeX3.1 directory, as well as the `README` file in the
`xdvi` directory for an explanation of the environment variables which must be set
for TeX and `xdvi`.  The file `site.h` in TeX3.1 contains the compiled-in values of the
TeX environment variables.

8. Most of the executables reside on amoeba in /public/util.  In addition, the
directories /public/module/tex and /public/module/mf will hold additional TeX and
MetaFont files, respectively.

9. Note also that the files `putw.o` and `getw.o` are not archived in the amoeba libraries,
although their sources exist in the amoeba source tree.  I moved `putw.c` and `getw.c` into 
the `amcommon` directory from the amoeba source directory so these could be compiled as
well.

10. Note that the utilities `tex`, `latex`, and `bibtex` on amoeba are actually shell scripts
which invoke `tex32`, `latex32`, and `bibtex32`.  (Big TeX is made by default.)  They
cause execution on the machine `ast`.  If this is not desirable in the future, the
install part of the Makefiles will have to be changed.

11. Make sure to read the README file for other details.

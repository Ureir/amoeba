> [!NOTE]
> File:		/home/amoeba5.3/sun4/README
>
> Last modified:  Mon Jul 15 13:11:00 MET DST 1996

This directory contains the compressed versions of the files needed to build
the Sun 3 coldstart tape.

The files you *need*:
```
  Name		   Size	      Description
make_sun-tape	   0.54 KB   a shell script to make the boot tape.  It expects
			   to run on a host with a QIC-150 tape
tapefile.0.sun4c 279.71 KB   the coldstart kernel for the sun4c
tapefile.0.sun4m 263.45 KB   the coldstart kernel for the sun4m
tapefile.1	   2.34 MB   the ramdisk image needed for the installation and
tapefile.2	  35.21 MB   a tar file containing the Amoeba binaries and
			   system files
```

Optional files are:
```
  Name		   Size	      Description

mmdf_sparc.tar	   5.70 MB   the binaries for the MMDF II email system
			   (This should be untarred in super/module)
x_sparc.tar	  60.12 MB   tar file containing the X Windows binaries
			   (This should be untarred in super/module)

NB. If you are having trouble ftping big files due to flakey network
    connections there is a split version of tapefile.2.Z available.
    INSTEAD of ftping tapefile.2.Z you can ftp Split_tape/tape2.Z.*
    and recombine them later with:
	cat tape2.Z.* | uncompress > tapefile.2
    These can be found in the directory Split_tape.  A split version of
    the X tar file is also available in the directory Split_x.
```

Make the directory BinTree.am under UNIX at the top level of the
distribution, if it doesn't already exist.  If it does exist make
sure it is empty.  The tapefile.2 file should be untarred in a new
directory BinTree.am.  Don't just overwrite the old one since some
of the old binaries may not be present in the new system and cause
confusion.

If you already have a running Amoeba system then BinTree.am can be
installed more or less directly onto your existing system but be
sure to avoid overwriting the files in /super/admin/bootinfo.  The
new versions of soap and the boot server and the new kernels must
be installed with great care.

Sums:
```
25766   158 tapefile.0.sun4c.Z
06896   175 tapefile.0.sun4m.Z
39834  1279 tapefile.1.Z
18386 20554 tapefile.2.Z
21733  3626 mmdf_sparc.tar.Z
52465 31427 x_sparc.tar.Z
30766  1024 Split_tape/tape2.Z.01
00955  1024 Split_tape/tape2.Z.02
31968  1024 Split_tape/tape2.Z.03
35050  1024 Split_tape/tape2.Z.04
00798  1024 Split_tape/tape2.Z.05
43278  1024 Split_tape/tape2.Z.06
36151  1024 Split_tape/tape2.Z.07
46153  1024 Split_tape/tape2.Z.08
36552  1024 Split_tape/tape2.Z.09
59122  1024 Split_tape/tape2.Z.10
40932  1024 Split_tape/tape2.Z.11
27869  1024 Split_tape/tape2.Z.12
35020  1024 Split_tape/tape2.Z.13
15922  1024 Split_tape/tape2.Z.14
14170  1024 Split_tape/tape2.Z.15
17547  1024 Split_tape/tape2.Z.16
16311  1024 Split_tape/tape2.Z.17
51962  1024 Split_tape/tape2.Z.18
07515  1024 Split_tape/tape2.Z.19
58783  1024 Split_tape/tape2.Z.20
19453    74 Split_tape/tape2.Z.21
10792  1024 Split_x/xtar.Z.01
30066  1024 Split_x/xtar.Z.02
17779  1024 Split_x/xtar.Z.03
14416  1024 Split_x/xtar.Z.04
51665  1024 Split_x/xtar.Z.05
49782  1024 Split_x/xtar.Z.06
43127  1024 Split_x/xtar.Z.07
49705  1024 Split_x/xtar.Z.08
44591  1024 Split_x/xtar.Z.09
12090  1024 Split_x/xtar.Z.10
63531  1024 Split_x/xtar.Z.11
02973  1024 Split_x/xtar.Z.12
27283  1024 Split_x/xtar.Z.13
17841  1024 Split_x/xtar.Z.14
14921  1024 Split_x/xtar.Z.15
06707  1024 Split_x/xtar.Z.16
02219  1024 Split_x/xtar.Z.17
35587  1024 Split_x/xtar.Z.18
59802  1024 Split_x/xtar.Z.19
45386  1024 Split_x/xtar.Z.20
52173  1024 Split_x/xtar.Z.21
31343  1024 Split_x/xtar.Z.22
04481  1024 Split_x/xtar.Z.23
59057  1024 Split_x/xtar.Z.24
54837  1024 Split_x/xtar.Z.25
27288  1024 Split_x/xtar.Z.26
13521  1024 Split_x/xtar.Z.27
13813  1024 Split_x/xtar.Z.28
59393  1024 Split_x/xtar.Z.29
14833  1024 Split_x/xtar.Z.30
40396   707 Split_x/xtar.Z.31
```

> [!NOTE]
> File:		/home/amoeba5.3/ibm_at/README
>
> Last modified:	Mon Jul 15 11:25:15 MET DST 1996

This directory contains the binaries for the 80386/80486 AT and PCI-bus PCs.

Files you need:
```
  Name		Size	   Description
kernels		 1.44 MB
ramdisk.[01]	 1.44 MB
amoeba.[01]	 1.44 MB   the floppy images needed to coldstart the 386
bintree.tar	 28.80 MB   tar file containing the i80x86 system binaries.
```

Additional files you may want are:
```
  Name		Size	   Description
mmdf_i80386.tar	  4.57 MB   the binaries for the MMDF II email system
			   (This should be untarred in super/module)
x_i80386.tar	 43.69 MB   tar file containing the X Windows binaries
			   (This should be untarred in super/module)
```

NB. If you are having trouble ftping big files due to flakey network
    connections there is a split version of `bintree.tar.Z` available.
    INSTEAD of ftping `bintree.tar.Z` you can ftp `Split_bin/bintar.Z.*`
    and recombine them later with:
	```
	cat bintar.Z.* | uncompress > bintree.tar
	```
    These can be found in the directory `Split_bin`.  A split version of
    the X tar file is also available in the directory `Split_x`.

Make the directory `BinTree.am` under UNIX at the top level of the
distribution, if it doesn't already exist.  If it does exist make
sure it is empty.  The bintree.tar file should be untarred in a new
directory `BinTree.am`.  Don't just overwrite the old one since some
of the old binaries may not be present in the new system and cause
confusion.

If you already have a running Amoeba system then BinTree.am can be
installed more or less directly onto your existing system but be
sure to avoid overwriting the files in `/super/admin/bootinfo`.  The
new versions of soap and the boot server and the new kernels must
be installed with great care.

The floppy images should be uncompressed and dumped on 1.44MB 3.5 inch
floppy disk using **dd**(1) under UNIX or **dwrite** under Amoeba.  NOTE, the
images must be dumped on the raw floppy device.

Sums:
```
07563  1440 kernels
36691  1440 ramdisk.0
13002  1440 ramdisk.1
06109  1440 amoeba.0
52244  1440 amoeba.1
26643 16586 bintree.tar.Z
55536  2942 mmdf_i80386.tar.Z
25537 26379 x_i80386.tar.Z

03790  1024 Split_bin/bintar.Z.01
56957  1024 Split_bin/bintar.Z.02
33375  1024 Split_bin/bintar.Z.03
19688  1024 Split_bin/bintar.Z.04
29921  1024 Split_bin/bintar.Z.05
14132  1024 Split_bin/bintar.Z.06
17633  1024 Split_bin/bintar.Z.07
38175  1024 Split_bin/bintar.Z.08
14492  1024 Split_bin/bintar.Z.09
03467  1024 Split_bin/bintar.Z.10
33357  1024 Split_bin/bintar.Z.11
34582  1024 Split_bin/bintar.Z.12
38547  1024 Split_bin/bintar.Z.13
55651  1024 Split_bin/bintar.Z.14
08268  1024 Split_bin/bintar.Z.15
54563  1024 Split_bin/bintar.Z.16
07428   202 Split_bin/bintar.Z.17
32047  1024 Split_x/xtar.Z.01
32796  1024 Split_x/xtar.Z.02
14365  1024 Split_x/xtar.Z.03
60870  1024 Split_x/xtar.Z.04
04145  1024 Split_x/xtar.Z.05
44751  1024 Split_x/xtar.Z.06
21639  1024 Split_x/xtar.Z.07
15203  1024 Split_x/xtar.Z.08
38436  1024 Split_x/xtar.Z.09
30776  1024 Split_x/xtar.Z.10
07009  1024 Split_x/xtar.Z.11
27122  1024 Split_x/xtar.Z.12
20439  1024 Split_x/xtar.Z.13
62511  1024 Split_x/xtar.Z.14
29144  1024 Split_x/xtar.Z.15
18944  1024 Split_x/xtar.Z.16
12931  1024 Split_x/xtar.Z.17
40510  1024 Split_x/xtar.Z.18
64710  1024 Split_x/xtar.Z.19
02101  1024 Split_x/xtar.Z.20
31768  1024 Split_x/xtar.Z.21
22253  1024 Split_x/xtar.Z.22
36265  1024 Split_x/xtar.Z.23
63950  1024 Split_x/xtar.Z.24
48123  1024 Split_x/xtar.Z.25
14733   779 Split_x/xtar.Z.26
```
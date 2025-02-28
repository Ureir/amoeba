> [!NOTE]
> File:		/home/amoeba5.3/sun3/README
>
> Last modified:  Mon Jul 15 13:11:12 MET DST 1996

This directory contains the compressed versions of the files needed to build
the Sun 3 coldstart tape.

The files you **need**:
```
  Name		Size	   Description
make_sun-tape	  0.17 KB   a shell script to make the boot tape.  It expects to
			   run on a host with a QIC-24 tape drive
tapefile.0	260.50 KB   the coldstart kernel
tapefile.1	  2.15 MB   the ramdisk image needed for the installation and
tapefile.2	 30.12 MB   a tar file containing the Amoeba binaries and
			   system files
```

Optional files are:
```
  Name		Size	   Description

mmdf_mc68000.tar  4.96 MB   the binaries for the MMDF II email system
			   (This should be untarred in super/module)
x_mc68000.tar	 46.01 MB   tar file containing the X Windows binaries
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
02023   142 tapefile.0.Z
03280   924 tapefile.1.Z
05795 14954 tapefile.2.Z
55269  2803 mmdf_mc68000.tar.Z
38629 26840 x_mc68000.tar.Z
08113  1024 Split_tape/tape2.Z.01
36141  1024 Split_tape/tape2.Z.02
57702  1024 Split_tape/tape2.Z.03
20888  1024 Split_tape/tape2.Z.04
35845  1024 Split_tape/tape2.Z.05
54000  1024 Split_tape/tape2.Z.06
63177  1024 Split_tape/tape2.Z.07
58073  1024 Split_tape/tape2.Z.08
31967  1024 Split_tape/tape2.Z.09
61967  1024 Split_tape/tape2.Z.10
37753  1024 Split_tape/tape2.Z.11
06701  1024 Split_tape/tape2.Z.12
05173  1024 Split_tape/tape2.Z.13
35811  1024 Split_tape/tape2.Z.14
21446   618 Split_tape/tape2.Z.15
00899  1024 Split_x/xtar.Z.01
53035  1024 Split_x/xtar.Z.02
04379  1024 Split_x/xtar.Z.03
46307  1024 Split_x/xtar.Z.04
17064  1024 Split_x/xtar.Z.05
55048  1024 Split_x/xtar.Z.06
20236  1024 Split_x/xtar.Z.07
03635  1024 Split_x/xtar.Z.08
48937  1024 Split_x/xtar.Z.09
50175  1024 Split_x/xtar.Z.10
43761  1024 Split_x/xtar.Z.11
42618  1024 Split_x/xtar.Z.12
02142  1024 Split_x/xtar.Z.13
12213  1024 Split_x/xtar.Z.14
37088  1024 Split_x/xtar.Z.15
27972  1024 Split_x/xtar.Z.16
05905  1024 Split_x/xtar.Z.17
18271  1024 Split_x/xtar.Z.18
07942  1024 Split_x/xtar.Z.19
33507  1024 Split_x/xtar.Z.20
06971  1024 Split_x/xtar.Z.21
56824  1024 Split_x/xtar.Z.22
28799  1024 Split_x/xtar.Z.23
44338  1024 Split_x/xtar.Z.24
10386  1024 Split_x/xtar.Z.25
61597  1024 Split_x/xtar.Z.26
19660   216 Split_x/xtar.Z.27
```

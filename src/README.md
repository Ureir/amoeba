> [!NOTE]
> File:          `/home/amoeba5.3/src/README`
>
> Last modified: Tue Jul 30 13:40:17 MET DST 1996

This directory contains the compressed tar file of the Amoeba source code.
The uncompressed `SRC.tar` is about 20.55 MB.

It also contains a script to upgrade an Amoeba 5.2 directory graph to
an Amoeba 5.3 directory graph.  This is in `upgrade.tar` (approx 8 KB).

Notes:

1.  `SRC.tar.Z` does not contain the src changes needed to build X11R6.
    These will be provided later.

2.  If you are having trouble FTPing big files due to flakey network
    connections there is a split version of `SRC.tar.Z` available.
    INSTEAD of FTPing `SRC.tar.Z` you can FTP `Split_src/SRC.Z.*` and
    reconnect them later with:
	```
	cat SRC.Z.* | uncompress > SRC.tar
	```

3.  If you already have a version of the Amoeba sources do NOT dump the new
    sources over the top of the old version.  Some files have been moved or
    deleted and so you will get an inconsistent source tree.  Therefore move
    the old sources somewhere else or delete them.

Untarring:
    Under UNIX:
	`SRC.tar` should be untarred at the top level of the Amoeba tree.
    Under Amoeba:
	`SRC.tar` should be untarred under `/super/module/amoeba`.
    (To untar it under Amoeba you will need a UNIX machine running the
    flip-driver and commands like
    ```
	W=/super/module/amoeba
	zcat SRC.tar.Z | ax -E _WORK= -C WORK= /bin/tar xvf -
    ```
    will untar it into the directory `/super/module/amoeba` for you.)

Patches:
    There are currently 2 patches available for Amoeba.
    ```
    patch1.tar - fixes a bug in aps and a bug in newsoapgraph
    patch2.tar - fixes a bug in ftpd and another bug in newsoapgraph
    ```

Sums:
```
57045  7611 SRC.tar.Z
48493     2 patch1.tar.Z
36094     7 patch2.tar.Z
19226     4 upgrade.tar.Z

11324  1024 Split_src/SRC.Z.01
01331  1024 Split_src/SRC.Z.02
34754  1024 Split_src/SRC.Z.03
55721  1024 Split_src/SRC.Z.04
58645  1024 Split_src/SRC.Z.05
42454  1024 Split_src/SRC.Z.06
15525  1024 Split_src/SRC.Z.07
54157   443 Split_src/SRC.Z.08
```

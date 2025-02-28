> [!NOTE]
> File:		`/home/amoeba5.3/README`
>
> Last updated:	Tue Apr 7, 1998

# Copyright

Although Amoeba is freely available, it **is** copyrighted.
See the file `COPYRIGHT` for details.

# README Files

There is a `README` file in each directory which explains what each file
is and gives a checksum (see `sum`(1) under UNIX) for checking that it
was correctly `FTP`ed.  Read the `README` files in the subdirectories to
avoid ftping unnecessary files!!  The large tar files are also split
into lots of smaller files and you don't need to take the split version
if you take the complete version.

# Frequently Asked Questions

Also read the `FAQ` file (frequently asked questions) in this directory.
It explains the RTFM system which you need to know about.

# What you need to FTP

You need the things from the generic directories (`unix`, `src`, `doc`).  The
binaries for each machine type, including X and MMDF binaries are in
`sun4`, `sun3` and `ibm_at` respectively.  Finally there is other third-party
software which is not part of Amoeba but which has been tried on Amoeba
and seems to work.  This is in the directory `thirdp` and is only
provided in source form.  You must compile it yourself.  If you want to
compile your Amoeba system with the GNU C compiler you will need some
configuration files from the directory `thirdp`.

Updates may be made available from time to time in the form of source code
patches.  Therefore it is a good idea to learn how to build your own
configurations and kernels.

# Getting Help

If you have technical questions, wish to report a bug, documentation
error or deficiency or have some constructive suggestions for improving
Amoeba then send them to:
	amoeba-support@cs.vu.nl
Note that the RTFM system applies to these reports/questions (see the FAQ).

Administrative announcements, including notification of new versions of
Amoeba will be posted to `comp.os.research` and `comp.os.misc`.  If you have
questions or issues about Amoeba that you would like to discuss we recommend
posting to `comp.os.misc` and/or `comp.os.research`, where appropriate.

> [!NOTE]
> Copyright 1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.2	94/04/06 11:42:03
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

To add new host label types proceed as follows:

 1. make the file "hostos"`\_dep.c` containing the routines for that host
    operating system.

 2. edit `config.c` and add the set of routines to the end of the `Host\_p` array
    and add an entry to the end of the `Host\_os\_menu`.

If you wish to add geometry info for a commonly used disk at your site then
this can be added to the table in `conf.c`

## WARNING:
    This program is painfully complicated.  Trying to ferret out bugs will
    give you a headache.  Only if the problem has no workaround should you
    attempt to modify this program.
    
    There be dragons and other wild things here!!  Abandon hope all ye who
    enter into this maze of pointers and incomprehensible doings.

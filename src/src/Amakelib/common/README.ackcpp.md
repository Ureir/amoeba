> [!NOTE]
>	README.ackcpp	1.2	94/04/06 10:30:55
>
> Copyright :copyright:1994 Vrije Universiteit, The Netherlands.
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

The ACK C-preprocesor is needed to generate the source file dependencies
that are to be checked by Amake.
A suitable ACK cpp binary can be found in `~amoeba/bin.<arch>`.

You can either
- change ACKCPPLIB in file `~amoeba/src/Amakelib/common/ackcpplib.amk`
or, better yet,
- on \<arch\> systems make `/usr/local/ambin` a symlink to `~amoeba/bin.<arch>`

The latter solution has the advantage that `sun3` and `sun4` configuration
trees can be generated independently (and in parallel as well).

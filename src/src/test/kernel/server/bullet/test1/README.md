> [!NOTE]
> Copyright :copyright:1994 Vrije Universiteit, The Netherlands.
>	
>	README	1.2	94/04/06 17:35:49
>
> For full copyright and restrictions on use see the file COPYRIGHT in the
> top level of the Amoeba distribution.

This test was written by Berend-Jan Beugel.
It makes some assumptions which are not true and is therefore liable
to report errors which are not in the server but in the program.
These mainly spring from the idea that if a **b\_modify** fails that the
**b\_modify** has not changed the file in the bullet server's cache.
**b\_modify** operations which are larger than 30000 bytes will in fact alter the
cache.

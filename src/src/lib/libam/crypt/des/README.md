> [!NOTE]
>	
>	README	1.1	91/11/18 16:24:07

This is a DES program package made by Antti Louko (alo@santra.hut.fi)

Copyright :copyright:1989 Antti Louko. All Rights Reserved.

COPYRIGHT FILE TELLS WHAT YOU ARE ALLOWED TO DO WITH THIS SOFTWARE

This program should compile just fine on VAX with BSD 4.3. On SUNS,
you should edit Makerules to include `-msoft-float` option if you don't
have FPU. For other machines you should typedef **des\_u\_long** to be an
unsigned 32-bit integer type. If processor needs aligned multi-byte
accesses, you may have to modify **copy\*-macros** in `des-private.h` file.

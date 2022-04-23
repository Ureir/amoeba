/*	@(#)crpnam.c	1.2	94/04/06 11:15:36 */
/*
 * Copyright 1994 Vrije Universiteit, The Netherlands.
 * For full copyright and restrictions on use see the file COPYRIGHT in the
 * top level of the Amoeba distribution.
 */

#include "em_private.h"

void
CC_crpnam(int op, char *p)
{
	/*	CON or ROM with argument PNAM(p)
	*/
	PS(op);
	PNAM(p);
	CEND();
	NL();
}

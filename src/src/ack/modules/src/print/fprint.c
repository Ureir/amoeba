/*	@(#)fprint.c	1.2	93/01/15 17:14:32 */
/*
 * (c) copyright 1987 by the Vrije Universiteit, Amsterdam, The Netherlands.
 * See the copyright notice in the ACK home directory, in the file "Copyright".
 */

#ifdef __STDC__
#include <stdarg.h>
#define va_dostart(ap, prm)	va_start(ap, prm)
#else
#include <varargs.h>
#define va_dostart(ap, prm)	va_start(ap)
#endif
#include <system.h>
#include "param.h"

/*VARARGS2*/
/*FORMAT1v $
	%s = char *
	%l = long
	%c = int
	%[uxbo] = unsigned int
	%d = int
$ */
fprintv(File *fp, char *fmt, va_list args)
{
	char buf[SSIZE];

	sys_write(fp, buf, _format(buf, fmt, args));
}

fprint(File *fp, char *fmt, ...)
{
	va_list args;

	va_dostart(args, fmt);
	fprintv(fp, fmt, args);
	va_end(args);
}

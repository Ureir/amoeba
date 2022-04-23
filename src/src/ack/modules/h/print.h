/*	@(#)print.h	1.1	91/04/11 13:46:20 */
/*
 * (c) copyright 1987 by the Vrije Universiteit, Amsterdam, The Netherlands.
 * See the copyright notice in the ACK home directory, in the file "Copyright".
 */

#define stdin	STDIN
#define stdout	STDOUT
#define stderr	STDERR

#define printf	print
#define sprintf	sprint
#define fprintf	fprint

#define FILE	File

#include <stdarg.h>

void fprint(File *f, char *fmt, ...);
void fprintv(File *f, char *fmt, va_list args);

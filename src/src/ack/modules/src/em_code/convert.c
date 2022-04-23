/*	@(#)convert.c	1.1	91/04/11 11:53:38 */
/*
 * (c) copyright 1987 by the Vrije Universiteit, Amsterdam, The Netherlands.
 * See the copyright notice in the ACK home directory, in the file "Copyright".
 */
#ifndef NORCSID
#endif

/*	This program converts either human-readable or compact EM
	assembly code to calls of the procedure-interface.
	It must be linked with two libraries:
	- a library to read EM code, according to read_em(3)
	- a library implementing the em_code(3) interface.
	Thus, this program could serve as an EM_encoder, an
	EM_decoder, or some code generator, depending on how it is
	linked.
*/

#include	<system.h>
#include        <em_pseu.h>
#include	<em_mnem.h>
#include        <em_spec.h>
#include        <em_flag.h>
#include        <em_ptyp.h>
#include	<em.h>
#include	<em_comp.h>
#include        "em_private.h"
#include        <print.h>

char *filename;			/* Name of input file */
int errors;			/* Number of errors */

int main(int argc, char **argv)
{
	struct e_instr buf;
	register struct e_instr *p = &buf;

	if (argc >= 2) {
		filename = argv[1];
	}
	else	filename = 0;
	if (!EM_open(filename)) {
		fatal(EM_error);
	}
	EM_getinstr(p);
	C_init((arith) EM_wordsize, (arith) EM_pointersize);
	if (argc >= 3) {
		if (!C_open(argv[2])) {
			fatal("C_open failed");
		}
	}
	else	if (!C_open( (char *) 0)) fatal("C_open failed");
	C_magic();
	while (p->em_type != EM_EOF) {
		if (p->em_type == EM_FATAL) {
			fatal("%s", EM_error);
		}
		if (EM_error) {
			error("%s", EM_error);
		}
		if (p->em_type != EM_ERROR) {
			EM_mkcalls(p);
		}
		EM_getinstr(p);
	}
	C_close();
	EM_close();
	return errors;
}

/* VARARGS */
void
errorv(char *s, va_list v)
{
	fprint(STDERR,
		"%s, line %d: ",
		filename ? filename : "standard input",
		EM_lineno);
	fprintv(STDERR,s,v);
	fprint(STDERR, "\n");
	errors++;
}

void
error(char *s, ...)
{
        va_list vl;

        va_start(vl,s);
        errorv(s, vl);
        va_end(vl);
}

/* VARARGS */
void
fatal(char *s,...)
{
        va_list vl;

        va_start(vl,s);
        errorv(s, vl);
        va_end(vl);
	exit(1);
}

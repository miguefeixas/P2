/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static float *
_add_1 (add_1_argument *argp, struct svc_req *rqstp)
{
	return (add_1_svc(argp->arg1, argp->arg2, rqstp));
}

static float *
_sub_1 (sub_1_argument *argp, struct svc_req *rqstp)
{
	return (sub_1_svc(argp->arg1, argp->arg2, rqstp));
}

static float *
_mul_1 (mul_1_argument *argp, struct svc_req *rqstp)
{
	return (mul_1_svc(argp->arg1, argp->arg2, rqstp));
}

static float *
_div_1 (div_1_argument *argp, struct svc_req *rqstp)
{
	return (div_1_svc(argp->arg1, argp->arg2, rqstp));
}

static calcV_res *
_addv_1 (addv_1_argument *argp, struct svc_req *rqstp)
{
	return (addv_1_svc(argp->arg1, argp->arg2, rqstp));
}

static calcV_res *
_subv_1 (subv_1_argument *argp, struct svc_req *rqstp)
{
	return (subv_1_svc(argp->arg1, argp->arg2, rqstp));
}

static calcV_res *
_mulv_1 (mulv_1_argument *argp, struct svc_req *rqstp)
{
	return (mulv_1_svc(argp->arg1, argp->arg2, rqstp));
}

static calcM_res *
_transpose_1 (matrix  *argp, struct svc_req *rqstp)
{
	return (transpose_1_svc(*argp, rqstp));
}

static bool_t *
_ispalindrome_1 (word  *argp, struct svc_req *rqstp)
{
	return (ispalindrome_1_svc(*argp, rqstp));
}

static void
calculatorprog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		add_1_argument add_1_arg;
		sub_1_argument sub_1_arg;
		mul_1_argument mul_1_arg;
		div_1_argument div_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case ADD:
		_xdr_argument = (xdrproc_t) xdr_add_1_argument;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _add_1;
		break;

	case SUB:
		_xdr_argument = (xdrproc_t) xdr_sub_1_argument;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _sub_1;
		break;

	case MUL:
		_xdr_argument = (xdrproc_t) xdr_mul_1_argument;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _mul_1;
		break;

	case DIV:
		_xdr_argument = (xdrproc_t) xdr_div_1_argument;
		_xdr_result = (xdrproc_t) xdr_float;
		local = (char *(*)(char *, struct svc_req *)) _div_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
calculatorvprog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		addv_1_argument addv_1_arg;
		subv_1_argument subv_1_arg;
		mulv_1_argument mulv_1_arg;
		matrix transpose_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case ADDV:
		_xdr_argument = (xdrproc_t) xdr_addv_1_argument;
		_xdr_result = (xdrproc_t) xdr_calcV_res;
		local = (char *(*)(char *, struct svc_req *)) _addv_1;
		break;

	case SUBV:
		_xdr_argument = (xdrproc_t) xdr_subv_1_argument;
		_xdr_result = (xdrproc_t) xdr_calcV_res;
		local = (char *(*)(char *, struct svc_req *)) _subv_1;
		break;

	case MULV:
		_xdr_argument = (xdrproc_t) xdr_mulv_1_argument;
		_xdr_result = (xdrproc_t) xdr_calcV_res;
		local = (char *(*)(char *, struct svc_req *)) _mulv_1;
		break;

	case TRANSPOSE:
		_xdr_argument = (xdrproc_t) xdr_matrix;
		_xdr_result = (xdrproc_t) xdr_calcM_res;
		local = (char *(*)(char *, struct svc_req *)) _transpose_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
palindromechecker_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		word ispalindrome_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case ISPALINDROME:
		_xdr_argument = (xdrproc_t) xdr_word;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) _ispalindrome_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CALCULATORPROG, CALCULATORVERS);
	pmap_unset (CALCULATORVPROG, CALCULATORVVERS);
	pmap_unset (PALINDROMECHECKER, PALINDROMECHECKERVERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULATORPROG, CALCULATORVERS, calculatorprog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULATORPROG, CALCULATORVERS, udp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULATORVPROG, CALCULATORVVERS, calculatorvprog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULATORVPROG, CALCULATORVVERS, udp).");
		exit(1);
	}
	if (!svc_register(transp, PALINDROMECHECKER, PALINDROMECHECKERVERS, palindromechecker_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (PALINDROMECHECKER, PALINDROMECHECKERVERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULATORPROG, CALCULATORVERS, calculatorprog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULATORPROG, CALCULATORVERS, tcp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULATORVPROG, CALCULATORVVERS, calculatorvprog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULATORVPROG, CALCULATORVVERS, tcp).");
		exit(1);
	}
	if (!svc_register(transp, PALINDROMECHECKER, PALINDROMECHECKERVERS, palindromechecker_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (PALINDROMECHECKER, PALINDROMECHECKERVERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}

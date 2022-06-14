/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_hello_api.h
 *
 * Code generation for function 'hello'
 *
 */

#ifndef _CODER_HELLO_API_H
#define _CODER_HELLO_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void hello(real_T num);

void hello_api(const mxArray *prhs);

void hello_atexit(void);

void hello_initialize(void);

void hello_terminate(void);

void hello_xil_shutdown(void);

void hello_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_hello_api.h) */

/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_xsquare_2_c_api.h
 *
 * Code generation for function 'xsquare_2_c'
 *
 */

#ifndef _CODER_XSQUARE_2_C_API_H
#define _CODER_XSQUARE_2_C_API_H

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
void xsquare_2_c(real_T x[4], real_T y[4]);

void xsquare_2_c_api(const mxArray *prhs, const mxArray **plhs);

void xsquare_2_c_atexit(void);

void xsquare_2_c_initialize(void);

void xsquare_2_c_terminate(void);

void xsquare_2_c_xil_shutdown(void);

void xsquare_2_c_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_xsquare_2_c_api.h) */

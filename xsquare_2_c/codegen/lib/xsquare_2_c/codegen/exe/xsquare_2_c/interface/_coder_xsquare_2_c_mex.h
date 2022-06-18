/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_xsquare_2_c_mex.h
 *
 * Code generation for function 'xsquare_2_c'
 *
 */

#ifndef _CODER_XSQUARE_2_C_MEX_H
#define _CODER_XSQUARE_2_C_MEX_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_xsquare_2_c_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                    int32_T nrhs, const mxArray *prhs[1]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_xsquare_2_c_mex.h) */

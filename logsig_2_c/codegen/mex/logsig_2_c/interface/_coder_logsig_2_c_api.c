/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_logsig_2_c_api.c
 *
 * Code generation for function '_coder_logsig_2_c_api'
 *
 */

/* Include files */
#include "_coder_logsig_2_c_api.h"
#include "logsig_2_c.h"
#include "logsig_2_c_data.h"
#include "logsig_2_c_mexutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void logsig_2_c_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T M;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  M = emlrt_marshallIn(&st, emlrtAliasP(prhs), "M");
  /* Invoke the target function */
  M = logsig_2_c(&st, M);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(M);
}

/* End of code generation (_coder_logsig_2_c_api.c) */

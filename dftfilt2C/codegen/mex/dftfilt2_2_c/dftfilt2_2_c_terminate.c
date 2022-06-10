/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * dftfilt2_2_c_terminate.c
 *
 * Code generation for function 'dftfilt2_2_c_terminate'
 *
 */

/* Include files */
#include "dftfilt2_2_c_terminate.h"
#include "_coder_dftfilt2_2_c_mex.h"
#include "dftfilt2_2_c_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void dftfilt2_2_c_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void dftfilt2_2_c_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (dftfilt2_2_c_terminate.c) */

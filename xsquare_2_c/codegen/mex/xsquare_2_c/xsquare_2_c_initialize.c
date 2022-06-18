/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * xsquare_2_c_initialize.c
 *
 * Code generation for function 'xsquare_2_c_initialize'
 *
 */

/* Include files */
#include "xsquare_2_c_initialize.h"
#include "_coder_xsquare_2_c_mex.h"
#include "rt_nonfinite.h"
#include "xsquare_2_c_data.h"

/* Function Definitions */
void xsquare_2_c_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (xsquare_2_c_initialize.c) */

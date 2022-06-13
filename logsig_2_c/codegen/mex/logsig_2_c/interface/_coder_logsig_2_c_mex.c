/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_logsig_2_c_mex.c
 *
 * Code generation for function '_coder_logsig_2_c_mex'
 *
 */

/* Include files */
#include "_coder_logsig_2_c_mex.h"
#include "_coder_logsig_2_c_api.h"
#include "logsig_2_c_data.h"
#include "logsig_2_c_initialize.h"
#include "logsig_2_c_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void logsig_2_c_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                            const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        10, "logsig_2_c");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "logsig_2_c");
  }
  /* Call the function. */
  logsig_2_c_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&logsig_2_c_atexit);
  /* Module initialization. */
  logsig_2_c_initialize();
  /* Dispatch the entry-point. */
  logsig_2_c_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  logsig_2_c_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, (const char_T *)"windows-1252", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_logsig_2_c_mex.c) */

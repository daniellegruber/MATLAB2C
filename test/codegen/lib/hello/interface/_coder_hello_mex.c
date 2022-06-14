/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_hello_mex.c
 *
 * Code generation for function 'hello'
 *
 */

/* Include files */
#include "_coder_hello_mex.h"
#include "_coder_hello_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)plhs;
  mexAtExit(&hello_atexit);
  /* Module initialization. */
  hello_initialize();
  /* Dispatch the entry-point. */
  unsafe_hello_mexFunction(nlhs, nrhs, prhs);
  /* Module termination. */
  hello_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, (const char_T *)"windows-1252", true);
  return emlrtRootTLSGlobal;
}

void unsafe_hello_mexFunction(int32_T nlhs, int32_T nrhs,
                              const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        5, "hello");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "hello");
  }
  /* Call the function. */
  hello_api(prhs[0]);
}

/* End of code generation (_coder_hello_mex.c) */

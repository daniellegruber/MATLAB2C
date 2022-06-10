/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_dftfilt2_2_c_api.c
 *
 * Code generation for function '_coder_dftfilt2_2_c_api'
 *
 */

/* Include files */
#include "_coder_dftfilt2_2_c_api.h"
#include "dftfilt2_2_c.h"
#include "dftfilt2_2_c_data.h"
#include "dftfilt2_2_c_emxutil.h"
#include "dftfilt2_2_c_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = {
    1,                         /* lineNo */
    1,                         /* colNo */
    "_coder_dftfilt2_2_c_api", /* fName */
    ""                         /* pName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *freqs,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const cell_wrap_0 u);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *freqs,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(freqs), &thisId);
  emlrtDestroyArray(&freqs);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const cell_wrap_0 u)
{
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  y = NULL;
  i = 1;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &i));
  b_y = NULL;
  iv[0] = 1;
  iv[1] = u.f1->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b((emlrtCTX)sp, m, &u.f1->data[0], 8);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  return y;
}

void dftfilt2_2_c_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  cell_wrap_0 wavelet;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T cycles;
  real_T freqs;
  real_T srate;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitMatrix_cell_wrap_0(&st, &wavelet, &n_emlrtRTEI);
  /* Marshall function inputs */
  freqs = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "freqs");
  cycles = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "cycles");
  srate = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "srate");
  /* Invoke the target function */
  dftfilt2_2_c(&st, freqs, cycles, srate, *(cell_wrap_0(*)[1]) & wavelet);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, wavelet);
  emxFreeMatrix_cell_wrap_0(&st, &wavelet);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_dftfilt2_2_c_api.c) */

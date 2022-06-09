/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_dftfilt2_2_c_api.c
 *
 * Code generation for function 'dftfilt2_2_c'
 *
 */

/* Include files */
#include "_coder_dftfilt2_2_c_api.h"
#include "_coder_dftfilt2_2_c_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131626U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "dftfilt2_2_c",                                       /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
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

static void emxFreeMatrix_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pMatrix);

static void emxFreeStruct_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pStruct);

static void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

static void emxInitMatrix_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pMatrix);

static void emxInitStruct_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pStruct);

static void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

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

static void emxFreeMatrix_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pMatrix)
{
  emxFreeStruct_cell_wrap_0(sp, pMatrix);
}

static void emxFreeStruct_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pStruct)
{
  emxFree_creal_T(sp, &pStruct->f1);
}

static void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T *)NULL) {
    if (((*pEmxArray)->data != (creal_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_creal_T *)NULL;
  }
}

static void emxInitMatrix_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pMatrix)
{
  emxInitStruct_cell_wrap_0(sp, pMatrix);
}

static void emxInitStruct_cell_wrap_0(const emlrtStack *sp,
                                      cell_wrap_0 *pStruct)
{
  emxInit_creal_T(sp, &pStruct->f1);
}

static void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray)
{
  emxArray_creal_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_creal_T *)emlrtMallocEmxArray(sizeof(emxArray_creal_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_creal_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
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
  emxInitMatrix_cell_wrap_0(&st, &wavelet);
  /* Marshall function inputs */
  freqs = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "freqs");
  cycles = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "cycles");
  srate = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "srate");
  /* Invoke the target function */
  dftfilt2_2_c(freqs, cycles, srate, *(cell_wrap_0(*)[1]) & wavelet);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, wavelet);
  emxFreeMatrix_cell_wrap_0(&st, &wavelet);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

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
  dftfilt2_2_c_xil_terminate();
  dftfilt2_2_c_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void dftfilt2_2_c_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
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

/* End of code generation (_coder_dftfilt2_2_c_api.c) */

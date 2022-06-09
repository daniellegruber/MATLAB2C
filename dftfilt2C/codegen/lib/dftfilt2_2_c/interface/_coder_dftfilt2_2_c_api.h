/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * _coder_dftfilt2_2_c_api.h
 *
 * Code generation for function 'dftfilt2_2_c'
 *
 */

#ifndef _CODER_DFTFILT2_2_C_API_H
#define _CODER_DFTFILT2_2_C_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  emxArray_creal_T *f1;
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void dftfilt2_2_c(real_T freqs, real_T cycles, real_T srate,
                  cell_wrap_0 wavelet[1]);

void dftfilt2_2_c_api(const mxArray *const prhs[3], const mxArray **plhs);

void dftfilt2_2_c_atexit(void);

void dftfilt2_2_c_initialize(void);

void dftfilt2_2_c_terminate(void);

void dftfilt2_2_c_xil_shutdown(void);

void dftfilt2_2_c_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_dftfilt2_2_c_api.h) */

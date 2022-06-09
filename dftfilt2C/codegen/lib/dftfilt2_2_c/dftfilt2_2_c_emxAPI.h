/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * dftfilt2_2_c_emxAPI.h
 *
 * Code generation for function 'dftfilt2_2_c_emxAPI'
 *
 */

#ifndef DFTFILT2_2_C_EMXAPI_H
#define DFTFILT2_2_C_EMXAPI_H

/* Include files */
#include "dftfilt2_2_c_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_creal_T *emxCreateND_creal_T(int numDimensions,
                                             const int *size);

extern emxArray_creal_T *
emxCreateWrapperND_creal_T(creal_T *data, int numDimensions, const int *size);

extern emxArray_creal_T *emxCreateWrapper_creal_T(creal_T *data, int rows,
                                                  int cols);

extern emxArray_creal_T *emxCreate_creal_T(int rows, int cols);

extern void emxDestroyArray_creal_T(emxArray_creal_T *emxArray);

extern void emxDestroyMatrix_cell_wrap_0(cell_wrap_0 emxArray[1]);

extern void emxInitMatrix_cell_wrap_01(cell_wrap_0 pMatrix[1]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (dftfilt2_2_c_emxAPI.h) */

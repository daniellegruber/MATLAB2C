/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * dftfilt2_2_c_emxutil.h
 *
 * Code generation for function 'dftfilt2_2_c_emxutil'
 *
 */

#ifndef DFTFILT2_2_C_EMXUTIL_H
#define DFTFILT2_2_C_EMXUTIL_H

/* Include files */
#include "dftfilt2_2_c_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFreeMatrix_cell_wrap_0(cell_wrap_0 *pMatrix);

extern void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct);

extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInitMatrix_cell_wrap_0(cell_wrap_0 *pMatrix);

extern void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct);

extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);

extern void emxInit_real_T(emxArray_real_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (dftfilt2_2_c_emxutil.h) */

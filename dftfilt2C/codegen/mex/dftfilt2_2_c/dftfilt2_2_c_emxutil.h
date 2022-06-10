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

#pragma once

/* Include files */
#include "dftfilt2_2_c_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxFreeMatrix_cell_wrap_0(const emlrtStack *sp, cell_wrap_0 *pMatrix);

void emxFreeStruct_cell_wrap_0(const emlrtStack *sp, cell_wrap_0 *pStruct);

void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInitMatrix_cell_wrap_0(const emlrtStack *sp, cell_wrap_0 *pMatrix,
                               const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_0(const emlrtStack *sp, cell_wrap_0 *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

/* End of code generation (dftfilt2_2_c_emxutil.h) */

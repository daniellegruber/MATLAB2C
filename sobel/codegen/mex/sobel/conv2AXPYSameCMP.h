/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * conv2AXPYSameCMP.h
 *
 * Code generation for function 'conv2AXPYSameCMP'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "sobel_types.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_conv2AXPYSameCMP(const emlrtStack *sp, const emxArray_real_T *a,
                        emxArray_real_T *c);

void conv2AXPYSameCMP(const emlrtStack *sp, const emxArray_real_T *a,
                      emxArray_real_T *c);

/* End of code generation (conv2AXPYSameCMP.h) */

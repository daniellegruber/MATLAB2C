/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * logsig_2_c_mexutil.h
 *
 * Code generation for function 'logsig_2_c_mexutil'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                          const emlrtMsgIdentifier *parentId);

real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                          const emlrtMsgIdentifier *msgId);

real_T emlrt_marshallIn(const emlrtStack *sp,
                        const mxArray *a__output_of_length_,
                        const char_T *identifier);

const mxArray *emlrt_marshallOut(const real_T u);

/* End of code generation (logsig_2_c_mexutil.h) */

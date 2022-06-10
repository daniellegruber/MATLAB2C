/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * dftfilt2_2_c.c
 *
 * Code generation for function 'dftfilt2_2_c'
 *
 */

/* Include files */
#include "dftfilt2_2_c.h"
#include "dftfilt2_2_c_data.h"
#include "dftfilt2_2_c_emxutil.h"
#include "dftfilt2_2_c_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    92,             /* lineNo */
    "dftfilt2_2_c", /* fcnName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    102,            /* lineNo */
    "dftfilt2_2_c", /* fcnName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    103,            /* lineNo */
    "dftfilt2_2_c", /* fcnName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

static emlrtRSInfo h_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" /* pathName
                                                                          */
};

static emlrtECInfo emlrtECI = {
    2,              /* nDims */
    103,            /* lineNo */
    18,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    2,              /* nDims */
    102,            /* lineNo */
    30,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo emlrtRTEI = {
    33,         /* lineNo */
    37,         /* colNo */
    "linspace", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" /* pName
                                                                           */
};

static emlrtRTEInfo c_emlrtRTEI = {
    49,         /* lineNo */
    20,         /* colNo */
    "linspace", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" /* pName
                                                                           */
};

static emlrtRTEInfo d_emlrtRTEI = {
    99,             /* lineNo */
    13,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI =
    {
        31,            /* lineNo */
        30,            /* colNo */
        "unsafeSxfun", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    103,            /* lineNo */
    18,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    103,            /* lineNo */
    45,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    103,            /* lineNo */
    37,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI =
    {
        76,                  /* lineNo */
        9,                   /* colNo */
        "eml_mtimes_helper", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    102,            /* lineNo */
    30,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    102,            /* lineNo */
    13,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    92,             /* lineNo */
    9,              /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    102,            /* lineNo */
    34,             /* colNo */
    "dftfilt2_2_c", /* fName */
    "C:"
    "\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\dftfilt2C\\dftfilt2"
    "_2_c.m" /* pName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, cell_wrap_0 *in1,
                             const emxArray_creal_T *in2,
                             const emxArray_real_T *in3);

static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, cell_wrap_0 *in1,
                             const emxArray_creal_T *in2,
                             const emxArray_real_T *in3)
{
  const creal_T *in2_data;
  const real_T *in3_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->f1->size[0] * in1->f1->size[1];
  in1->f1->size[0] = 1;
  if (in3->size[1] == 1) {
    in1->f1->size[1] = in2->size[1];
  } else {
    in1->f1->size[1] = in3->size[1];
  }
  emxEnsureCapacity_creal_T(sp, in1->f1, i, &k_emlrtRTEI);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  if (in3->size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    real_T d;
    d = in3_data[i * stride_1_1];
    in1->f1->data[i].re = d * in2_data[i * stride_0_1].re;
    in1->f1->data[i].im = d * in2_data[i * stride_0_1].im;
  }
}

static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_in1, &f_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = 1;
  if (in2->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2->size[1];
  }
  emxEnsureCapacity_real_T(sp, b_in1, i, &f_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in2->size[1] != 1);
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_1] - in2_data[i * stride_1_1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &f_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void dftfilt2_2_c(const emlrtStack *sp, real_T freqs, real_T cycles,
                  real_T srate, cell_wrap_0 wavelet[1])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_creal_T *y;
  emxArray_real_T *b;
  emxArray_real_T *r;
  emxArray_real_T *winval;
  creal_T *y_data;
  real_T d1;
  real_T delta1;
  real_T delta2;
  real_T winlenint;
  real_T *b_data;
  real_T *r1;
  real_T *winval_data;
  int32_T i;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  dftfilt2() - discrete complex wavelet filters */
  /*  */
  /*  Usage: */
  /*    >> wavelet = dftfilt2( freqs, cycles, srate, cyclefact) */
  /*  */
  /*  Inputs: */
  /*    freqs    - frequency array */
  /*    cycles   - cycles array. If one value is given, all wavelets have */
  /*               the same number of cycles. If two values are given, the */
  /*               two values are used for the number of cycles at the lowest */
  /*               frequency and at the highest frequency, with linear  */
  /*               interpolation between these values for intermediate */
  /*               frequencies */
  /*    srate    - sampling rate (in Hz) */
  /*  */
  /*    cycleinc - ['linear'|'log'] increase mode if [min max] cycles is */
  /*               provided in 'cycle' parameter. {default: 'linear'} */
  /*    type     - ['sinus'|'morlet'] wavelet type is a sinusoid with */
  /*               cosine (real) and sine (imaginary) parts tapered by */
  /*               a Hanning or Morlet function. 'morlet' is a typical Morlet */
  /*               wavelet (with p=2*pi and sigma=0.7) best matching the  */
  /*               'sinus' Hanning taper) {default: 'morlet'} */
  /*  Output: */
  /*    wavelet - cell array of wavelet filters */
  /*  */
  /*  Note: The length of the window is automatically computed from the  */
  /*        number of cycles and is always made odd. */
  /*  */
  /*  Authors: Arnaud Delorme, SCCN/INC/UCSD, La Jolla, 3/28/2003 */
  /*  Copyright (C) 3/28/2003 Arnaud Delorme 8, SCCN/INC/UCSD, arno@salk.edu */
  /*  */
  /*  This file is part of EEGLAB, see http://www.eeglab.org */
  /*  for the documentation and details. */
  /*  */
  /*  Redistribution and use in source and binary forms, with or without */
  /*  modification, are permitted provided that the following conditions are
   * met: */
  /*  */
  /*  1. Redistributions of source code must retain the above copyright notice,
   */
  /*  this list of conditions and the following disclaimer. */
  /*  */
  /*  2. Redistributions in binary form must reproduce the above copyright
   * notice, */
  /*  this list of conditions and the following disclaimer in the documentation
   */
  /*  and/or other materials provided with the distribution. */
  /*  */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
   * IS" */
  /*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   */
  /*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   */
  /*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   */
  /*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR */
  /*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF */
  /*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   */
  /*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN */
  /*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) */
  /*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF */
  /*  THE POSSIBILITY OF SUCH DAMAGE. */
  /*  compute number of cycles at each frequency */
  /*  ------------------------------------------ */
  /*  compute wavelet */
  /*  number of cycles depend on window size  */
  /*  number of cycles automatically reduced if smaller window */
  /*  note: as the number of cycle changes, the frequency shifts a little */
  /*        this has to be fixed */
  winlenint = muDoubleScalarFloor(cycles * srate / freqs);
  if (muDoubleScalarIsNaN(winlenint) || muDoubleScalarIsInf(winlenint)) {
    delta2 = rtNaN;
  } else if (winlenint == 0.0) {
    delta2 = 0.0;
  } else {
    delta2 = muDoubleScalarRem(winlenint, 2.0);
    if (delta2 == 0.0) {
      delta2 = 0.0;
    } else if (winlenint < 0.0) {
      delta2 += 2.0;
    }
  }
  if (delta2 == 1.0) {
    winlenint++;
  }
  st.site = &emlrtRSI;
  d1 = winlenint / 2.0;
  delta2 = -winlenint / 2.0;
  emxInit_real_T(&st, &winval, &l_emlrtRTEI);
  if (!(winlenint + 1.0 >= 0.0)) {
    if (muDoubleScalarIsNaN(winlenint + 1.0)) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                    "Coder:toolbox:MustNotBeNaN",
                                    "Coder:toolbox:MustNotBeNaN", 3, 4, 1, "N");
    }
    winval->size[1] = 0;
  } else {
    i = winval->size[0] * winval->size[1];
    winval->size[0] = 1;
    winval->size[1] = (int32_T)(winlenint + 1.0);
    emxEnsureCapacity_real_T(&st, winval, i, &c_emlrtRTEI);
    winval_data = winval->data;
    if ((int32_T)(winlenint + 1.0) >= 1) {
      nx = (int32_T)(winlenint + 1.0) - 1;
      winval_data[(int32_T)(winlenint + 1.0) - 1] = delta2;
      if (winval->size[1] >= 2) {
        winval_data[0] = d1;
        if (winval->size[1] >= 3) {
          if ((d1 == -delta2) && ((int32_T)(winlenint + 1.0) > 2)) {
            delta2 /= (real_T)(int32_T)(winlenint + 1.0) - 1.0;
            for (k = 2; k <= nx; k++) {
              winval_data[k - 1] =
                  (real_T)(((k << 1) - (int32_T)(winlenint + 1.0)) - 1) *
                  delta2;
            }
            if (((int32_T)(winlenint + 1.0) & 1) == 1) {
              winval_data[(int32_T)(winlenint + 1.0) >> 1] = 0.0;
            }
          } else if (((d1 < 0.0) != (delta2 < 0.0)) &&
                     ((muDoubleScalarAbs(d1) > 8.9884656743115785E+307) ||
                      (muDoubleScalarAbs(delta2) > 8.9884656743115785E+307))) {
            delta1 = d1 / ((real_T)winval->size[1] - 1.0);
            delta2 /= (real_T)winval->size[1] - 1.0;
            i = winval->size[1];
            for (k = 0; k <= i - 3; k++) {
              winval_data[k + 1] = (d1 + delta2 * ((real_T)k + 1.0)) -
                                   delta1 * ((real_T)k + 1.0);
            }
          } else {
            delta1 = (delta2 - d1) / ((real_T)winval->size[1] - 1.0);
            i = winval->size[1];
            for (k = 0; k <= i - 3; k++) {
              winval_data[k + 1] = d1 + ((real_T)k + 1.0) * delta1;
            }
          }
        }
      }
    }
  }
  /*  Morlet */
  i = winval->size[0] * winval->size[1];
  winval->size[0] = 1;
  emxEnsureCapacity_real_T(sp, winval, i, &d_emlrtRTEI);
  winval_data = winval->data;
  nx = winval->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    winval_data[i] = freqs * winval_data[i] / srate;
  }
  emxInit_real_T(sp, &r, &e_emlrtRTEI);
  delta2 = cycles / 5.0;
  st.site = &c_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  st.site = &c_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = winval->size[1];
  emxEnsureCapacity_real_T(sp, r, i, &e_emlrtRTEI);
  r1 = r->data;
  nx = winval->size[1];
  for (i = 0; i < nx; i++) {
    delta1 = winval_data[i];
    r1[i] = delta1 * delta1;
  }
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  emxEnsureCapacity_real_T(sp, r, i, &f_emlrtRTEI);
  r1 = r->data;
  winlenint = delta2 * delta2;
  delta2 = 2.0 * winlenint;
  nx = r->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    r1[i] = -r1[i] / delta2;
  }
  emxInit_real_T(sp, &b, &g_emlrtRTEI);
  st.site = &c_emlrtRSI;
  b_exp(&st, r);
  st.site = &c_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  st.site = &c_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  st.site = &c_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  st.site = &c_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = winval->size[1];
  emxEnsureCapacity_real_T(sp, b, i, &e_emlrtRTEI);
  b_data = b->data;
  nx = winval->size[1];
  for (i = 0; i < nx; i++) {
    delta1 = winval_data[i];
    b_data[i] = delta1 * delta1;
  }
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  emxEnsureCapacity_real_T(sp, b, i, &g_emlrtRTEI);
  b_data = b->data;
  delta2 = 39.478417604357432 * winlenint / 4.0;
  nx = b->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    b_data[i] = -b_data[i] / winlenint - delta2;
  }
  st.site = &c_emlrtRSI;
  b_exp(&st, b);
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  emxEnsureCapacity_real_T(sp, b, i, &h_emlrtRTEI);
  b_data = b->data;
  nx = b->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    b_data[i] *= 1.4142135623730951;
  }
  if ((r->size[1] != b->size[1]) && ((r->size[1] != 1) && (b->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(r->size[1], b->size[1], &emlrtECI,
                                (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &y, &m_emlrtRTEI);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = winval->size[1];
  emxEnsureCapacity_creal_T(sp, y, i, &i_emlrtRTEI);
  y_data = y->data;
  nx = winval->size[1];
  for (i = 0; i < nx; i++) {
    y_data[i].re = 6.2831853071795862 * (winval_data[i] * 0.0);
    y_data[i].im = 6.2831853071795862 * winval_data[i];
  }
  emxFree_real_T(sp, &winval);
  st.site = &b_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  nx = y->size[1];
  c_st.site = &e_emlrtRSI;
  if (y->size[1] > 2147483646) {
    d_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    if (y_data[k].im == 0.0) {
      y_data[k].re = muDoubleScalarExp(y_data[k].re);
      y_data[k].im = 0.0;
    } else if (muDoubleScalarIsInf(y_data[k].im) &&
               muDoubleScalarIsInf(y_data[k].re) && (y_data[k].re < 0.0)) {
      y_data[k].re = 0.0;
      y_data[k].im = 0.0;
    } else {
      delta2 = muDoubleScalarExp(y_data[k].re / 2.0);
      y_data[k].re = delta2 * (delta2 * muDoubleScalarCos(y_data[k].im));
      y_data[k].im = delta2 * (delta2 * muDoubleScalarSin(y_data[k].im));
    }
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, y, i, &j_emlrtRTEI);
  y_data = y->data;
  nx = y->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    delta2 = y_data[i].re;
    winlenint = y_data[i].im;
    if (winlenint == 0.0) {
      delta1 = delta2 / 2.5066282746310002;
      delta2 = 0.0;
    } else if (delta2 == 0.0) {
      delta1 = 0.0;
      delta2 = winlenint / 2.5066282746310002;
    } else {
      delta1 = delta2 / 2.5066282746310002;
      delta2 = winlenint / 2.5066282746310002;
    }
    y_data[i].re = delta1;
    y_data[i].im = delta2;
  }
  if (r->size[1] == b->size[1]) {
    nx = r->size[1] - 1;
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    emxEnsureCapacity_real_T(sp, r, i, &f_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i <= nx; i++) {
      r1[i] -= b_data[i];
    }
  } else {
    st.site = &c_emlrtRSI;
    minus(&st, r, b);
    r1 = r->data;
  }
  emxFree_real_T(sp, &b);
  if ((y->size[1] != r->size[1]) && ((y->size[1] != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(y->size[1], r->size[1], &b_emlrtECI,
                                (emlrtCTX)sp);
  }
  if (y->size[1] == r->size[1]) {
    i = wavelet[0].f1->size[0] * wavelet[0].f1->size[1];
    wavelet[0].f1->size[0] = 1;
    wavelet[0].f1->size[1] = y->size[1];
    emxEnsureCapacity_creal_T(sp, wavelet[0].f1, i, &k_emlrtRTEI);
    nx = y->size[1];
    for (i = 0; i < nx; i++) {
      wavelet[0].f1->data[i].re = r1[i] * y_data[i].re;
      wavelet[0].f1->data[i].im = r1[i] * y_data[i].im;
    }
  } else {
    st.site = &b_emlrtRSI;
    binary_expand_op(&st, &wavelet[0], y, r);
  }
  emxFree_real_T(sp, &r);
  emxFree_creal_T(sp, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (dftfilt2_2_c.c) */

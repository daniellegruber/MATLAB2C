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
#include "dftfilt2_2_c_emxutil.h"
#include "dftfilt2_2_c_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op(cell_wrap_0 *in1, const emxArray_creal_T *in2,
                             const emxArray_real_T *in4,
                             const emxArray_real_T *in5);

/* Function Definitions */
static void binary_expand_op(cell_wrap_0 *in1, const emxArray_creal_T *in2,
                             const emxArray_real_T *in4,
                             const emxArray_real_T *in5)
{
  const creal_T *in2_data;
  const double *in4_data;
  const double *in5_data;
  int b_in5;
  int i;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  in5_data = in5->data;
  in4_data = in4->data;
  in2_data = in2->data;
  i = in1->f1->size[0] * in1->f1->size[1];
  in1->f1->size[0] = 1;
  if (in5->size[1] == 1) {
    b_in5 = in4->size[1];
  } else {
    b_in5 = in5->size[1];
  }
  if (b_in5 == 1) {
    in1->f1->size[1] = in2->size[1];
  } else if (in5->size[1] == 1) {
    in1->f1->size[1] = in4->size[1];
  } else {
    in1->f1->size[1] = in5->size[1];
  }
  emxEnsureCapacity_creal_T(in1->f1, i);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in4->size[1] != 1);
  stride_2_1 = (in5->size[1] != 1);
  if (in5->size[1] == 1) {
    b_in5 = in4->size[1];
  } else {
    b_in5 = in5->size[1];
  }
  if (b_in5 == 1) {
    b_in5 = in2->size[1];
  } else if (in5->size[1] == 1) {
    b_in5 = in4->size[1];
  } else {
    b_in5 = in5->size[1];
  }
  for (i = 0; i < b_in5; i++) {
    double ai;
    double in2_im;
    double in2_re;
    in2_im = in2_data[i * stride_0_1].re;
    ai = in2_data[i * stride_0_1].im;
    if (ai == 0.0) {
      in2_re = in2_im / 2.5066282746310002;
      in2_im = 0.0;
    } else if (in2_im == 0.0) {
      in2_re = 0.0;
      in2_im = ai / 2.5066282746310002;
    } else {
      in2_re = in2_im / 2.5066282746310002;
      in2_im = ai / 2.5066282746310002;
    }
    ai = in4_data[i * stride_1_1] -
         1.4142135623730951 * in5_data[i * stride_2_1];
    in1->f1->data[i].re = ai * in2_re;
    in1->f1->data[i].im = ai * in2_im;
  }
}

void dftfilt2_2_c(double freqs, double cycles, double srate,
                  cell_wrap_0 wavelet[1])
{
  emxArray_creal_T *y;
  emxArray_real_T *r;
  emxArray_real_T *winval;
  emxArray_real_T *x;
  creal_T *y_data;
  double d1;
  double delta2;
  double winlenint;
  double *r1;
  double *winval_data;
  double *x_data;
  int i;
  int k;
  int nx;
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
  winlenint = floor(cycles * srate / freqs);
  if (rtIsNaN(winlenint) || rtIsInf(winlenint)) {
    delta2 = rtNaN;
  } else if (winlenint == 0.0) {
    delta2 = 0.0;
  } else {
    delta2 = fmod(winlenint, 2.0);
    if (delta2 == 0.0) {
      delta2 = 0.0;
    } else if (winlenint < 0.0) {
      delta2 += 2.0;
    }
  }
  if (delta2 == 1.0) {
    winlenint++;
  }
  d1 = winlenint / 2.0;
  delta2 = -winlenint / 2.0;
  emxInit_real_T(&winval);
  if (!(winlenint + 1.0 >= 0.0)) {
    winval->size[1] = 0;
  } else {
    i = winval->size[0] * winval->size[1];
    winval->size[0] = 1;
    winval->size[1] = (int)(winlenint + 1.0);
    emxEnsureCapacity_real_T(winval, i);
    winval_data = winval->data;
    if ((int)(winlenint + 1.0) >= 1) {
      nx = (int)(winlenint + 1.0) - 1;
      winval_data[(int)(winlenint + 1.0) - 1] = delta2;
      if (winval->size[1] >= 2) {
        winval_data[0] = d1;
        if (winval->size[1] >= 3) {
          if ((d1 == -delta2) && ((int)(winlenint + 1.0) > 2)) {
            delta2 /= (double)(int)(winlenint + 1.0) - 1.0;
            for (k = 2; k <= nx; k++) {
              winval_data[k - 1] =
                  (double)(((k << 1) - (int)(winlenint + 1.0)) - 1) * delta2;
            }
            if (((int)(winlenint + 1.0) & 1) == 1) {
              winval_data[(int)(winlenint + 1.0) >> 1] = 0.0;
            }
          } else if (((d1 < 0.0) != (delta2 < 0.0)) &&
                     ((fabs(d1) > 8.9884656743115785E+307) ||
                      (fabs(delta2) > 8.9884656743115785E+307))) {
            winlenint = d1 / ((double)winval->size[1] - 1.0);
            delta2 /= (double)winval->size[1] - 1.0;
            i = winval->size[1];
            for (k = 0; k <= i - 3; k++) {
              winval_data[k + 1] = (d1 + delta2 * ((double)k + 1.0)) -
                                   winlenint * ((double)k + 1.0);
            }
          } else {
            winlenint = (delta2 - d1) / ((double)winval->size[1] - 1.0);
            i = winval->size[1];
            for (k = 0; k <= i - 3; k++) {
              winval_data[k + 1] = d1 + ((double)k + 1.0) * winlenint;
            }
          }
        }
      }
    }
  }
  /*  Morlet */
  i = winval->size[0] * winval->size[1];
  winval->size[0] = 1;
  emxEnsureCapacity_real_T(winval, i);
  winval_data = winval->data;
  nx = winval->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    winval_data[i] = freqs * winval_data[i] / srate;
  }
  emxInit_real_T(&r);
  delta2 = cycles / 5.0;
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = winval->size[1];
  emxEnsureCapacity_real_T(r, i);
  r1 = r->data;
  nx = winval->size[1];
  for (i = 0; i < nx; i++) {
    winlenint = winval_data[i];
    r1[i] = winlenint * winlenint;
  }
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  emxEnsureCapacity_real_T(r, i);
  r1 = r->data;
  delta2 *= delta2;
  winlenint = 2.0 * delta2;
  nx = r->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    r1[i] = -r1[i] / winlenint;
  }
  nx = r->size[1];
  for (k = 0; k < nx; k++) {
    r1[k] = exp(r1[k]);
  }
  emxInit_real_T(&x);
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = winval->size[1];
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  nx = winval->size[1];
  for (i = 0; i < nx; i++) {
    winlenint = winval_data[i];
    x_data[i] = winlenint * winlenint;
  }
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  winlenint = 39.478417604357432 * delta2 / 4.0;
  nx = x->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    x_data[i] = -x_data[i] / delta2 - winlenint;
  }
  nx = x->size[1];
  for (k = 0; k < nx; k++) {
    x_data[k] = exp(x_data[k]);
  }
  emxInit_creal_T(&y, 2);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = winval->size[1];
  emxEnsureCapacity_creal_T(y, i);
  y_data = y->data;
  nx = winval->size[1];
  for (i = 0; i < nx; i++) {
    y_data[i].re = 6.2831853071795862 * (winval_data[i] * 0.0);
    y_data[i].im = 6.2831853071795862 * winval_data[i];
  }
  emxFree_real_T(&winval);
  nx = y->size[1];
  for (k = 0; k < nx; k++) {
    if (y_data[k].im == 0.0) {
      y_data[k].re = exp(y_data[k].re);
      y_data[k].im = 0.0;
    } else if (rtIsInf(y_data[k].im) && rtIsInf(y_data[k].re) &&
               (y_data[k].re < 0.0)) {
      y_data[k].re = 0.0;
      y_data[k].im = 0.0;
    } else {
      delta2 = exp(y_data[k].re / 2.0);
      y_data[k].re = delta2 * (delta2 * cos(y_data[k].im));
      y_data[k].im = delta2 * (delta2 * sin(y_data[k].im));
    }
  }
  if (r->size[1] == 1) {
    i = x->size[1];
  } else {
    i = r->size[1];
  }
  if ((r->size[1] == x->size[1]) && (y->size[1] == i)) {
    i = wavelet[0].f1->size[0] * wavelet[0].f1->size[1];
    wavelet[0].f1->size[0] = 1;
    wavelet[0].f1->size[1] = y->size[1];
    emxEnsureCapacity_creal_T(wavelet[0].f1, i);
    nx = y->size[1];
    for (i = 0; i < nx; i++) {
      delta2 = y_data[i].re;
      winlenint = y_data[i].im;
      if (winlenint == 0.0) {
        d1 = delta2 / 2.5066282746310002;
        delta2 = 0.0;
      } else if (delta2 == 0.0) {
        d1 = 0.0;
        delta2 = winlenint / 2.5066282746310002;
      } else {
        d1 = delta2 / 2.5066282746310002;
        delta2 = winlenint / 2.5066282746310002;
      }
      winlenint = r1[i] - 1.4142135623730951 * x_data[i];
      wavelet[0].f1->data[i].re = winlenint * d1;
      wavelet[0].f1->data[i].im = winlenint * delta2;
    }
  } else {
    binary_expand_op(&wavelet[0], y, r, x);
  }
  emxFree_real_T(&r);
  emxFree_real_T(&x);
  emxFree_creal_T(&y);
}

/* End of code generation (dftfilt2_2_c.c) */

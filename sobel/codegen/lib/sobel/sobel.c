/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * sobel.c
 *
 * Code generation for function 'sobel'
 *
 */

/* Include files */
#include "sobel.h"
#include "conv2AXPYSameCMP.h"
#include "sobel_data.h"
#include "sobel_emxutil.h"
#include "sobel_initialize.h"
#include "sobel_types.h"
#include <math.h>

/* Function Declarations */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2);

/* Function Definitions */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  if (in2->size[0] == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in2->size[0];
  }
  if (in2->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2->size[1];
  }
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    if (in2->size[0] == 1) {
      b_loop_ub = in1->size[0];
    } else {
      b_loop_ub = in2->size[0];
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      double in1_tmp;
      in1_tmp = in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] *
              in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in1_tmp * in1_tmp;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(&b_in1);
}

void sobel(const emxArray_real_T *originalImage, double threshold,
           emxArray_uint8_T *edgeImage)
{
  emxArray_real_T *H;
  emxArray_real_T *V;
  double *H_data;
  double *V_data;
  int k;
  int nx;
  unsigned char *edgeImage_data;
  if (!isInitialized_sobel) {
    sobel_initialize();
  }
  emxInit_real_T(&H, 2);
  emxInit_real_T(&V, 2);
  /*  edgeImage = sobel(originalImage, threshold) */
  /*  Sobel edge detection. Given a normalized image (with double values) */
  /*  return an image where the edges are detected w.r.t. threshold value. */
  conv2AXPYSameCMP(originalImage, H);
  H_data = H->data;
  b_conv2AXPYSameCMP(originalImage, V);
  V_data = V->data;
  if ((H->size[0] == V->size[0]) && (H->size[1] == V->size[1])) {
    nx = H->size[0] * H->size[1];
    for (k = 0; k < nx; k++) {
      H_data[k] = H_data[k] * H_data[k] + V_data[k] * V_data[k];
    }
  } else {
    binary_expand_op(H, V);
    H_data = H->data;
  }
  emxFree_real_T(&V);
  nx = H->size[0] * H->size[1];
  for (k = 0; k < nx; k++) {
    H_data[k] = sqrt(H_data[k]);
  }
  k = edgeImage->size[0] * edgeImage->size[1];
  edgeImage->size[0] = H->size[0];
  edgeImage->size[1] = H->size[1];
  emxEnsureCapacity_uint8_T(edgeImage, k);
  edgeImage_data = edgeImage->data;
  nx = H->size[0] * H->size[1];
  for (k = 0; k < nx; k++) {
    edgeImage_data[k] = (unsigned char)((H_data[k] > threshold) * 255U);
  }
  emxFree_real_T(&H);
}

/* End of code generation (sobel.c) */

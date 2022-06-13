/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * conv2AXPYSameCMP.c
 *
 * Code generation for function 'conv2AXPYSameCMP'
 *
 */

/* Include files */
#include "conv2AXPYSameCMP.h"
#include "sobel_emxutil.h"
#include "sobel_types.h"
#include "omp.h"
#include <string.h>

/* Function Definitions */
void b_conv2AXPYSameCMP(const emxArray_real_T *a, emxArray_real_T *c)
{
  static const signed char b[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
  double cj_data[1024];
  const double *a_data;
  double *c_data;
  int b_i;
  int bij;
  int i;
  int ib;
  int imax;
  int imin;
  int j;
  int jb;
  int jbmax;
  int jbmin;
  int ma;
  int na;
  a_data = a->data;
  ma = a->size[0];
  na = a->size[1];
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    int ub_loop;
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(c, i);
    c_data = c->data;
    ub_loop = a->size[0] * a->size[1];
    for (i = 0; i < ub_loop; i++) {
      c_data[i] = 0.0;
    }
  } else {
    int jcut;
    int ub_loop;
    jcut = a->size[1] - 1;
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(c, i);
    c_data = c->data;
    ub_loop = a->size[1] - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    imax, imin, bij, jbmax, jbmin, cj_data, jb, ib, b_i)

    for (j = 0; j <= ub_loop; j++) {
      if (ma - 1 >= 0) {
        memset(&cj_data[0], 0, ma * sizeof(double));
      }
      jbmin = (j + 1 <= 1);
      if (j + 1 < jcut) {
        jbmax = 2;
      } else {
        jbmax = na - j;
      }
      for (jb = jbmin; jb <= jbmax; jb++) {
        for (ib = 0; ib < 3; ib++) {
          bij = b[(3 * (2 - jb) - ib) + 2];
          if (ib < 1) {
            imin = 2;
            imax = ma;
          } else {
            imin = 1;
            imax = (ma - ib) + 1;
          }
          for (b_i = imin; b_i <= imax; b_i++) {
            cj_data[b_i - 1] +=
                (double)bij *
                a_data[((b_i + ib) + a->size[0] * ((j + jb) - 1)) - 2];
          }
        }
      }
      for (imax = 0; imax < ma; imax++) {
        c_data[imax + c->size[0] * j] = cj_data[imax];
      }
    }
  }
}

void conv2AXPYSameCMP(const emxArray_real_T *a, emxArray_real_T *c)
{
  static const signed char b[9] = {1, 0, -1, 2, 0, -2, 1, 0, -1};
  double cj_data[1024];
  const double *a_data;
  double *c_data;
  int b_i;
  int bij;
  int i;
  int ib;
  int imax;
  int imin;
  int j;
  int jb;
  int jbmax;
  int jbmin;
  int ma;
  int na;
  a_data = a->data;
  ma = a->size[0];
  na = a->size[1];
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    int ub_loop;
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(c, i);
    c_data = c->data;
    ub_loop = a->size[0] * a->size[1];
    for (i = 0; i < ub_loop; i++) {
      c_data[i] = 0.0;
    }
  } else {
    int jcut;
    int ub_loop;
    jcut = a->size[1] - 1;
    i = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(c, i);
    c_data = c->data;
    ub_loop = a->size[1] - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    imax, imin, bij, jbmax, jbmin, cj_data, jb, ib, b_i)

    for (j = 0; j <= ub_loop; j++) {
      if (ma - 1 >= 0) {
        memset(&cj_data[0], 0, ma * sizeof(double));
      }
      jbmin = (j + 1 <= 1);
      if (j + 1 < jcut) {
        jbmax = 2;
      } else {
        jbmax = na - j;
      }
      for (jb = jbmin; jb <= jbmax; jb++) {
        for (ib = 0; ib < 3; ib++) {
          bij = b[(3 * (2 - jb) - ib) + 2];
          if (ib < 1) {
            imin = 2;
            imax = ma;
          } else {
            imin = 1;
            imax = (ma - ib) + 1;
          }
          for (b_i = imin; b_i <= imax; b_i++) {
            cj_data[b_i - 1] +=
                (double)bij *
                a_data[((b_i + ib) + a->size[0] * ((j + jb) - 1)) - 2];
          }
        }
      }
      for (imax = 0; imax < ma; imax++) {
        c_data[imax + c->size[0] * j] = cj_data[imax];
      }
    }
  }
}

/* End of code generation (conv2AXPYSameCMP.c) */

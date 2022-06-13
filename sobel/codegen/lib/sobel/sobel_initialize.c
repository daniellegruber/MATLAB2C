/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * sobel_initialize.c
 *
 * Code generation for function 'sobel_initialize'
 *
 */

/* Include files */
#include "sobel_initialize.h"
#include "sobel_data.h"
#include "omp.h"

/* Function Definitions */
void sobel_initialize(void)
{
  omp_init_nest_lock(&sobel_nestLockGlobal);
  isInitialized_sobel = true;
}

/* End of code generation (sobel_initialize.c) */

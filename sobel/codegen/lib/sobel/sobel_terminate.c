/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * sobel_terminate.c
 *
 * Code generation for function 'sobel_terminate'
 *
 */

/* Include files */
#include "sobel_terminate.h"
#include "sobel_data.h"
#include "omp.h"

/* Function Definitions */
void sobel_terminate(void)
{
  omp_destroy_nest_lock(&sobel_nestLockGlobal);
  isInitialized_sobel = false;
}

/* End of code generation (sobel_terminate.c) */

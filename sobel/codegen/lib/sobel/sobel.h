/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * sobel.h
 *
 * Code generation for function 'sobel'
 *
 */

#ifndef SOBEL_H
#define SOBEL_H

/* Include files */
#include "rtwtypes.h"
#include "sobel_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void sobel(const emxArray_real_T *originalImage, double threshold,
                  emxArray_uint8_T *edgeImage);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (sobel.h) */

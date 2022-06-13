/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * logsig_2_c_emxutil.h
 *
 * Code generation for function 'logsig_2_c_emxutil'
 *
 */

#ifndef LOGSIG_2_C_EMXUTIL_H
#define LOGSIG_2_C_EMXUTIL_H

/* Include files */
#include "logsig_2_c_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel);

extern void emxFree_char_T(emxArray_char_T **pEmxArray);

extern void emxInit_char_T(emxArray_char_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (logsig_2_c_emxutil.h) */

/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * logsig_2_c.c
 *
 * Code generation for function 'logsig_2_c'
 *
 */

/* Include files */
#include "logsig_2_c.h"
#include "logsig_2_c_emxutil.h"
#include "logsig_2_c_mexutil.h"
#include "logsig_2_c_types.h"
#include "rt_nonfinite.h"
#include "emlrt.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = {
    19,           /* lineNo */
    1,            /* colNo */
    "logsig_2_c", /* fName */
    "C:\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\logsig_2_"
    "c\\logsig_2_c.m" /* pName */
};

static emlrtRSInfo emlrtRSI = {
    19,           /* lineNo */
    "logsig_2_c", /* fcnName */
    "C:\\Users\\danie\\OneDrive\\Documents\\MATLAB\\MATLAB2C\\logsig_2_"
    "c\\logsig_2_c.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    29,        /* lineNo */
    "sprintf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

static emlrtMCInfo emlrtMCI = {
    53,              /* lineNo */
    14,              /* colNo */
    "nonConstPrint", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pName
                                                                           */
};

static emlrtMCInfo b_emlrtMCI = {
    55,              /* lineNo */
    15,              /* colNo */
    "nonConstPrint", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pName
                                                                           */
};

static emlrtDCInfo emlrtDCI = {
    57,              /* lineNo */
    53,              /* colNo */
    "nonConstPrint", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m", /* pName
                                                                            */
    4 /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    57,        /* lineNo */
    5,         /* colNo */
    "sprintf", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pName
                                                                           */
};

static emlrtRSInfo c_emlrtRSI = {
    53,              /* lineNo */
    "nonConstPrint", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

static emlrtRSInfo d_emlrtRSI = {
    55,              /* lineNo */
    "nonConstPrint", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

static emlrtRSInfo e_emlrtRSI = {
    58,              /* lineNo */
    "nonConstPrint", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

/* Function Declarations */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmpStr,
                               const char_T *identifier, emxArray_char_T *y);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo *location);

static const mxArray *length(const emlrtStack *sp, const mxArray *m1,
                             emlrtMCInfo *location);

/* Function Definitions */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmpStr,
                               const char_T *identifier, emxArray_char_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(tmpStr), &thisId, y);
  emlrtDestroyArray(&tmpStr);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  char_T *ret_data;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 3, &pArrays[0],
                               (const char_T *)"feval", true, location);
}

static const mxArray *length(const emlrtStack *sp, const mxArray *m1,
                             emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 1, &pArray,
                               (const char_T *)"length", true, location);
}

real_T logsig_2_c(const emlrtStack *sp, real_T M)
{
  static const int32_T iv[2] = {1, 7};
  static const int32_T iv1[2] = {1, 5};
  static const char_T u[7] = {'s', 'p', 'r', 'i', 'n', 't', 'f'};
  static const char_T formatSpec[5] = {'%', '0', '.', '5', 'f'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_char_T *charStr;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *tmpStr;
  const mxArray *y;
  real_T l;
  real_T strSize;
  int32_T iv2[2];
  char_T *charStr_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_char_T(sp, &charStr, &b_emlrtRTEI);
  /*  Compute the sigmoid function (e.g. used in logistic regression). */
  /*  Copyright (C) Christian Kothe, SCCN, 2011, christian@sccn.ucsd.edu */
  /*  */
  /*  This program is free software; you can redistribute it and/or modify it
   * under the terms of the GNU */
  /*  General Public License as published by the Free Software Foundation;
   * either version 2 of the */
  /*  License, or (at your option) any later version. */
  /*  */
  /*  This program is distributed in the hope that it will be useful, but
   * WITHOUT ANY WARRANTY; without */
  /*  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
   * PURPOSE.  See the GNU */
  /*  General Public License for more details. */
  /*  */
  /*  You should have received a copy of the GNU General Public License along
   * with this program; if not, */
  /*  write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   * Boston, MA  02111-1307 */
  /*  USA */
  l = 1.0 / (muDoubleScalarExp(-M) + 1.0);
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  tmpStr = NULL;
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = NULL;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(&b_st, 5, m, &formatSpec[0]);
  emlrtAssign(&b_y, m);
  c_st.site = &c_emlrtRSI;
  emlrtAssign(&tmpStr, feval(&c_st, y, b_y, emlrt_marshallOut(l), &emlrtMCI));
  c_st.site = &d_emlrtRSI;
  strSize =
      emlrt_marshallIn(&c_st, length(&c_st, emlrtAlias(tmpStr), &b_emlrtMCI),
                       "<output of length>");
  if (!(strSize >= 0.0)) {
    emlrtNonNegativeCheckR2012b(strSize, &emlrtDCI, &b_st);
  }
  c_st.site = &e_emlrtRSI;
  c_emlrt_marshallIn(&c_st, emlrtAlias(tmpStr), "tmpStr", charStr);
  charStr_data = charStr->data;
  emlrtDestroyArray(&tmpStr);
  c_y = NULL;
  iv2[0] = 1;
  iv2[1] = charStr->size[1];
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, charStr->size[1], m, &charStr_data[0]);
  emlrtAssign(&c_y, m);
  emlrtDisplayR2012b(c_y, (char_T *)"ans", &emlrtRTEI, (emlrtCTX)sp);
  emxFree_char_T(sp, &charStr);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return l;
}

/* End of code generation (logsig_2_c.c) */

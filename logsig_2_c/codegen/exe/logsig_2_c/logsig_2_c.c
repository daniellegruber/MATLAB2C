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
#include "logsig_2_c_types.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

/* Custom Source Code */
#include "main.h"

/* Function Definitions */
double logsig_2_c(double M)
{
  emxArray_char_T *str;
  double l;
  int i;
  int nbytes;
  char *str_data;
  emxInit_char_T(&str);
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
  l = 1.0 / (exp(-M) + 1.0);
  nbytes = (int)snprintf(NULL, 0, "%0.5f", l) + 1;
  i = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes;
  emxEnsureCapacity_char_T(str, i);
  str_data = str->data;
  snprintf(&str_data[0], (size_t)nbytes, "%0.5f", l);
  emxFree_char_T(&str);
  return l;
}

/* End of code generation (logsig_2_c.c) */

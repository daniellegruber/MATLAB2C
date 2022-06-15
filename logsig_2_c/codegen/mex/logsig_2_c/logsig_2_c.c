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
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
real_T logsig_2_c(real_T M)
{
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
  return 1.0 / (muDoubleScalarExp(-M) + 1.0);
}

/* End of code generation (logsig_2_c.c) */

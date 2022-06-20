/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
// * xsquare_2_c.c
  * xsquare_2_c.c
 *
 * Code generation for function 'xsquare_2_c'
 *
 */

/* Include files */
#include "xsquare_2_c.h"

/* Function Definitions */
//void xsquare_2_c(const double x[4], double y[4])
double * xsquare_2_c(double *p_x)
{
static double y[4];
  y[0] = x[0] * x[0]; // replace x with p_x or let x = *p_x, x[0] = *p_x, x[1] = *(p_x + 1), x[2] = *(p_x + 2)...
  y[1] = x[1] * x[1];
  y[2] = x[2] * x[2];
  y[3] = x[3] * x[3];
  return  y;
}

/* End of code generation (xsquare_2_c.c) */

/* p=a;
q=b;
for (i=0; i<MAX; i++)
{
    *q = *p;
    q++;
    p++;
} */

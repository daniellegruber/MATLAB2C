/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include <stdio.h>
#include "main.h"
#include "xsquare_2_c.h"
#include "xsquare_2_c_terminate.h"

/* Function Declarations */
static void argInit_2x2_real_T(double result[4]);

static double argInit_real_T(void);

//static void main_xsquare_2_c(void);
static double * main_xsquare_2_c(double *p_x);

/* Function Definitions */
static void argInit_2x2_real_T(double result[4])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + (idx1 << 1)] = argInit_real_T();
    }
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

//static void main_xsquare_2_c(void)
static double * main_xsquare_2_c(double *p_x)
{
  double dv[4];
//  double y[4];
  double *p_y;
  /* Initialize function 'xsquare_2_c' input arguments. */
  /* Initialize function input argument 'x'. */
  /* Call the entry-point 'xsquare_2_c'. */
  argInit_2x2_real_T(dv);
//  xsquare_2_c(dv, y);
  p_y = xsquare_2_c(p_x);
  int k;
  for ( k = 0; k < 4; k++ ) {
      printf("*(p_y + [%d]) : %d\n", k, *(p_y + k) );
  }
}

int main(int argc, char **argv)
{
//  (void)argc;
//  (void)argv;
  double *p_x;
  double *p_y;
  if (argc != 2) {
  printf('Expected 1 arguments: p_x\n');
  exit(-1);
  }
  p_x= atof(argv[1]);
  int i=0;
  printf("\nexe name=%s", argv[0]);
  for (i=1; i< argc; i++) {
  printf("\narg%d=%s", i, argv[i]);
   }
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
//  main_xsquare_2_c();
  p_y = main_xsquare_2_c(p_x);
  int k;
  for ( k = 0; k < 4; k++ ) {
      printf("*(p_y + [%d]) : %d\n", k, *(p_y + k) );
  }
  /* Terminate the application.
You do not need to do this more than one time. */
  xsquare_2_c_terminate();
  return 0;
}

/* End of code generation (main.c) */


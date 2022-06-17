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
#include "logsig_2_c.h"
#include "logsig_2_c_terminate.h"

/* Function Declarations */
static double argInit_real_T(void);

//static double main_logsig_2_c(void);
static double main_logsig_2_c(double M);

/* Function Definitions */
static double argInit_real_T(void)
{
  return 0.0;
}

//static double main_logsig_2_c(void)
static double main_logsig_2_c(double M)
{
  double l;
  /* Initialize function 'logsig_2_c' input arguments. */
  /* Call the entry-point 'logsig_2_c'. */
//  l = logsig_2_c(argInit_real_T());
  l = logsig_2_c(M);
  printf("\nl=%f",l);
  return l;
}

//int main(int argc, char **argv)
double main(int argc, char **argv)
{
//  (void)argc;
//  (void)argv;
  double M;
  double l;
  M= atof(argv[1]);
  if (argc != 2) {
  printf('Expected 1 arguments: M\n');
  exit(-1);
  }
  int i=0;
  printf("\nexe name=%s", argv[0]);
  for (i=1; i< argc; i++) {
  printf("\narg%d=%s", i, argv[i]);
   }
  printf("\nM=%f",M);
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
//  main_logsig_2_c();
   l = main_logsig_2_c(M);
  /* Terminate the application.
You do not need to do this more than one time. */
  logsig_2_c_terminate();
//  return 0;
  return  l;
}

/* End of code generation (main.c) */


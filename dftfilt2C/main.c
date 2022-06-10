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
#include "main.h"
#include "dftfilt2_2_c.h"
#include "dftfilt2_2_c_emxAPI.h"
#include "dftfilt2_2_c_terminate.h"
#include "dftfilt2_2_c_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static double argInit_real_T(void);

static void main_dftfilt2_2_c(void);

/* Function Definitions */
static double argInit_real_T(void)
{
  return 0.0;
}

static void main_dftfilt2_2_c(double freqs, int cycles, double srate)
{
  cell_wrap_0 wavelet;
  double freqs_tmp;
  emxInitMatrix_cell_wrap_01(*(cell_wrap_0(*)[1]) & wavelet);
  /* Initialize function 'dftfilt2_2_c' input arguments. */
  freqs_tmp = argInit_real_T();
  /* Call the entry-point 'dftfilt2_2_c'. */
  dftfilt2_2_c(freqs_tmp, freqs_tmp, freqs_tmp, *(cell_wrap_0(*)[1]) & wavelet);
  emxDestroyMatrix_cell_wrap_0(*(cell_wrap_0(*)[1]) & wavelet);
}

int main(int argc, char **argv)
{
//   (void)argc;
//   (void)argv;
    double freqs;
    int cycles;
    double srate;


  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */

    freqs = argv[1];
    cycles = argv[2];
    srate = argv[3];

  main_dftfilt2_2_c(freqs, cycles, srate);

  /* Terminate the application.
You do not need to do this more than one time. */
  dftfilt2_2_c_terminate();
  return 0;
}

/* End of code generation (main.c) */

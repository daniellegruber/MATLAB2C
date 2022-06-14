/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * hello_initialize.c
 *
 * Code generation for function 'hello_initialize'
 *
 */

/* Include files */
#include "hello_initialize.h"
#include "fileManager.h"
#include "hello_data.h"

/* Function Definitions */
void hello_initialize(void)
{
  filedata_init();
  isInitialized_hello = true;
}

/* End of code generation (hello_initialize.c) */

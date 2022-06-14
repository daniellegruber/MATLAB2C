/*
 * Student License - for use by students to meet course requirements and
 * perform academic research at degree granting institutions only.  Not
 * for government, commercial, or other organizational use.
 *
 * hello.c
 *
 * Code generation for function 'hello'
 *
 */

/* Include files */
#include "hello.h"
#include "fileManager.h"
#include "hello_data.h"
#include "hello_initialize.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

/* Function Declarations */
static double rt_roundd_snf(double u);

/* Function Definitions */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void hello(double num)
{
  FILE *filestar;
  signed char b_fileid;
  signed char fileid;
  boolean_T autoflush;
  if (!isInitialized_hello) {
    hello_initialize();
  }
  fileid = cfopen();
  b_fileid = fileid;
  if ((fileid > 22) || (fileid < 0)) {
    b_fileid = -1;
  }
  if (b_fileid >= 3) {
    filestar = eml_openfiles[b_fileid - 3];
    autoflush = eml_autoflush[b_fileid - 3];
  } else if (b_fileid == 0) {
    filestar = stdin;
    autoflush = true;
  } else if (b_fileid == 1) {
    filestar = stdout;
    autoflush = true;
  } else if (b_fileid == 2) {
    filestar = stderr;
    autoflush = true;
  } else {
    filestar = NULL;
    autoflush = true;
  }
  if (fileid == 0) {
    filestar = NULL;
  }
  if (!(filestar == NULL)) {
    size_t bytesOutSizet;
    double d;
    unsigned char u;
    d = rt_roundd_snf(num);
    if (d < 256.0) {
      if (d >= 0.0) {
        u = (unsigned char)d;
      } else {
        u = 0U;
      }
    } else if (d >= 256.0) {
      u = MAX_uint8_T;
    } else {
      u = 0U;
    }
    bytesOutSizet = fwrite(&u, sizeof(unsigned char), (size_t)1, filestar);
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      fflush(filestar);
    }
  }
}

/* End of code generation (hello.c) */

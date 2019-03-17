#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

double f (double x, void * param);
struct Params {
  double a,v,w,b,c;
};
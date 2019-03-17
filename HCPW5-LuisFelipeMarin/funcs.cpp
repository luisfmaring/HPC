#include "gdsIntegral.h"

double f (double x, void * param) {
  Params* p = (Params*)param;
  return p->a*sin(cos(p->v-p->w*x))+p->b*x-p->c*x*x;
}
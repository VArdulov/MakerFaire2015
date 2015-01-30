#ifndef _H_NUMERICAL_SOLVER
#define _H_NUMERICAL_SOLVER

#include <stdlib.h>
#include <math.h>

typedef float Real;
typedef Real (*c_func)(Real);

const Real ACCURECY = 0.0005;
const int MAX_ITER = 500;

Real find_zero_scent(c_func F, Real x0, Real x1){
  for(int i = 0; i < MAX_ITER; i++){
    if(fabs(F(x0)) < ACCURECY)
      return x0;
    Real slope = (F(x0) - F(x1))/ (x0 - x1); 
    Real x_n = x0 -F(x0) / slope;
    x1 = x0;
    x0 = x_n;
  }
  return -69;
}

#endif

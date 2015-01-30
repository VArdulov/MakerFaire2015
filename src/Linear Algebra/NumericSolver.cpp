#include "NumericSolver.h"
#include "Vector.h"

#define DEBUG 1


#if DEBUG
#include <math.h>
#include <stdio.h>

Vector Circ(3);
Vector CircOri1(3);
Vector CircOri2(3);
Vector P(3);

float ServoRodLength;
float VisherRodLength;

void set_values(){
  Circ[0] = 10; Circ[1] = 0; Circ[2] = 0;
  CircOri1[0] = 0; CircOri1[1] = 0; CircOri1[2] = 1;
  CircOri2[0] = 0; CircOri2[1] = 1; CircOri2[2] = 0;
  P[0] = -2.02; P[1] = -2; P[2] = -15;
  
  ServoRodLength = 5.0;
  VisherRodLength = 20.0;
}
float func_2(float x){
  return (Circ + (cos(x) * CircOri1 + 
		  sin(x) * CircOri2) * ServoRodLength
	  - P
	  ).norm() - VisherRodLength;
}

float func_1(float x){
  return 2.0 - x * x;
}
int main(){
  set_values();
  printf("%f \n", find_zero_scent(func_2, 1, 0.5));
  return 0;
}
#endif

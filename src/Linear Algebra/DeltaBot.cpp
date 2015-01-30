#include "Vector.h"
#include "DeltaBot.h"

#include <stdio.h>
#include <math.h>


#define PI 3.1415926535f
#define DEBUG 1

static const Real ACCURECY = 0.0005;
static const int MAX_ITER = 500;

Real DeltaBot::Func(Real x, int i){
  return (Circ[i] + (cos(x) * CircOri[i][0] + 
		     sin(x) * CircOri[i][1]) * ServoRodLength
	  - P
	  ).norm() - VisherRodLength;
}
Real DeltaBot::comp_angle(int ind){
  Real x0 = 1; Real x1 = 0.5;
  for(int i = 0; i < MAX_ITER; i++){
    if(fabs( Func(x0, ind) ) < ACCURECY)
      return x0;
    Real slope = (Func(x0, ind) - Func(x1, ind)) / (x0 - x1);
    //    printf("here: x0: %f  x1: %f slope: %f\n", x0,x1, slope);
    Real x_n = x0 - Func(x0, ind) / slope;
    x1 = x0;
    x0 = x_n;
  }
  return -69.0;
}


#if DEBUG
int main(){
  printf("testing delta bot class \n");
  
  DeltaBot D;
  bool b = D.go_to( Vector(-2.02, -2, -15) );
  return 0;
}
#endif

Vector DeltaBot::compute_angles(){
  Vector Q(3);
  for(int i = 0; i < 3; i++){
    Q[i] = comp_angle(i);
    printf("angle computed: %f \n", Q[i]);
  }
  return Q;
}
bool DeltaBot::go_to(Vector v){
  printf("going to: "); v.print();
  Vector Q = compute_angles();
  if(Q[0] == -69 || Q[1] == -69 || Q[2] == -69)
    return false;
  Q.print();
  for(int i = 0; i < 3; i++)
    set_servo_to_angle(i,Q[i]);
  return true;
}
void DeltaBot::set_servo_to_angle(int ind, Real angle){
  //do nothing so far.
}
DeltaBot::DeltaBot(){
  configure_pins();
  init_vars();
}
void DeltaBot::tringle_init(){
  Real DeltaSize = 10;
  for(int i = 0; i < 3; i++){
    Circ[i] = DeltaSize * Vector(
				 cos(2.0 * i * PI / 3.0),
				 sin(2.0 * i * PI / 3.0),
				 0);
    CircOri[i][0] = Vector(0, 0, 1);
    CircOri[i][1] = cross(CircOri[i][0], Circ[i] ).unit();
  }
}
void DeltaBot::init_vars(){
  VisherRodLength = 20;
  ServoRodLength = 5;
  alloc_vars();
  P[0] = -2.02; P[1] = -2.0; P[2] = -15;
  tringle_init();
}
void DeltaBot::alloc_vars(){
  P = Vector(3);
  Q = Vector(3);
  for(int i = 0; i < 3; i++){
    Circ[i] = Vector(3);
    CircOri[i][0] = Vector(3);
    CircOri[i][1] = Vector(3);
  }
}
void DeltaBot::configure_pins(){
  
}

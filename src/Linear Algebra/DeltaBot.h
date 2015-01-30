#ifndef _H_DELTA_BOT
#define _H_DELTA_BOT

#include "Vector.h"

class DeltaBot{
 public:
  DeltaBot();
  void init_vars();
  void configure_pins();
  bool go_to(Vector V);
  
 private:
  unsigned char servo_pins[3];
  void set_servo_to_angle(int servo, Real theta);
  Vector compute_angles();
  Real comp_angle(int i);
  //values

  Real VisherRodLength;
  Real ServoRodLength;
  
  Vector P;
  Vector Circ[3];
  Vector CircOri[3][2];
  Vector Q; // <- Angles
  
  Real Func(Real thet, int i);
  Real numeric_solve();
  void alloc_vars();
  void tringle_init();
};


#endif




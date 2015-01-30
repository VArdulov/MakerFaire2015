#ifndef _H_VECTOR
#define _H_VECTOR
#include <stdlib.h>

typedef float Real;

class Vector{
 public:
  Vector();
  Vector(int n);
  Vector(Real x, Real y, Real z);
  Vector(Real x, Real y);
  ~Vector();
  
  Vector(const Vector& v);
  Vector& operator=(const Vector& other);
  
  int size() const;
  Real norm() const;
  
  Real& operator[](size_t ind);
  const Real& operator[](size_t ind) const;
  void print() const;
  Vector unit() const;
 private:
  Real* arr; 
  size_t length;
};
Real dot(const Vector& r, const Vector& l);
Vector cross(const Vector& r, const Vector& l);
Vector operator+(Vector l, const Vector& r);
Vector operator-(Vector l, const Vector& r);
Vector operator*(const Real& sc, Vector l);
Vector operator*(Vector l, const Real& sc);


#endif

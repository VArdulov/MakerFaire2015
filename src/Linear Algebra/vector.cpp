#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

//#define DEBUG_VECTOR 1


#if DEBUG_VECTOR
int main(){
  srand(time(NULL));
  Vector v1 = random_vector(3, 10);
  Vector v2 = random_vector(3, 10);
  v1.print();
  v2.print();
  Vector c = cross(v1, v2);
  c.print();
  printf("%f \n", dot(c,v1));
  return 0;
}
#endif
Vector random_vector(int n , int M){
  Vector v(n);
  for(int i = 0; i < n; i++){
    v[i] = rand() % M;
  }
  return v;
}
Real dot(const Vector& v, const Vector& x){
  Real sum = 0;
  for(int i = 0; i < v.size(); i++){
    sum += v[i] * x[i];
  }
  return sum;
}

Vector cross(const Vector& v, const Vector& x){
  Vector res(3);
  res[0] = v[1] * x[2] - v[2] * x[1];
  res[1] = -(v[0] * x[2] - v[2] * x[0]);
  res[2] = v[0] * x[1] - v[1] * x[0];
  return res;
}
void Vector::print() const{
  printf("\n");
  for(int i = 0; i < length; i++){
    printf("%10.2f", arr[i]);
  }
  printf("\n");
}
Vector Vector::unit() const{
  Vector v = Vector(*this);
  return (v * (1.0 / v.norm()));
}
Vector operator+(Vector l, const Vector& r){
  for(int i = 0; i < l.size(); i++){
    l[i] += r[i];
  }
  return l;
}
Vector operator-(Vector l, const Vector& r){
  for(int i = 0; i < l.size(); i++){
    l[i] -= r[i];
  }
  return l;
}
Vector operator*(const Real& scl, Vector v){
  for(int i = 0; i < v.size(); i++){
    v[i] *= scl;
  }
  return v;
}
Vector operator*(Vector v, const Real& scl){
  return scl * v;
}

Real& Vector::operator[](size_t ind){
  return arr[ind];
}
const Real& Vector::operator[](size_t ind) const{
  return arr[ind];
}
Real Vector::norm() const{
  Real sum = 0;
  for(int i = 0; i < length; i++){
    sum += arr[i] * arr[i];
  }
  return sqrt(sum);
}
int Vector::size() const{
  return length;
}
Vector::Vector(){
  arr = new Real[1];
  length = 1;
  arr[0] = 0;
}
Vector::Vector(int n){
  arr = new Real[n];
  length = n;
  for(int i = 0; i < n; i++)
    arr[i] = 0;
}
Vector::Vector(Real x, Real y, Real z){
  arr = new Real[3];
  length = 3;
  arr[0] = x;
  arr[1] = y;
  arr[2] = z;
}
Vector::Vector(Real x, Real y){
  arr = new Real[2];
  length = 2;
  arr[0] = x;
  arr[1] = y;
}
Vector::~Vector(){
  delete [] arr;
}
Vector::Vector(const Vector& v){
  length = v.size();
  arr = new Real[length];
  for(int i = 0; i < v.size(); i++){
    arr[i] = v[i];
  }
}
Vector& Vector::operator=(const Vector& other){
  if(this != &other){
    delete [] arr; 
    length = other.size();
    arr = new Real[length];
    for(int i = 0; i < length; i++){
      arr[i] = other[i];
    }
  }
  return *this;
}

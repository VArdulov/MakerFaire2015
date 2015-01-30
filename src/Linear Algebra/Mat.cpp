#include <iostream>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

#include "Mat.h"
using namespace std;

#define DEBUG_MAT 1

#if DEBUG_MAT
int main(){
  srand(time(NULL));
  
  cout << "testing matrix" << endl;
  
  Mat m = random_mat(3, 2, 6);
  Vector v = random_vector(2,6);
  print(m);
  cout << endl << endl;
  v.print();
  cout << endl << endl;
  (m * v).print();
  return 0;
}
#endif
Vector operator*(const Mat& left_side, const Vector& right_side){
  assert(left_side.get_cols() == right_side.size());
  Vector v(left_side.get_rows());
  for(int i = 0; i < v.size(); i++){
    Real sum = 0;
    for(int k = 0; k < left_side.get_cols(); k++){
      sum += left_side.get(i, k) * right_side[k];
    }
    v[i] = sum;
  }
  return v;
}
Mat operator*(const Mat& left_side, const Mat& right_side){
  assert(left_side.get_cols() == right_side.get_rows());
  
  Mat m(left_side.get_rows(), right_side.get_cols());
  for(int i = 0; i < left_side.get_rows(); i++){
    for(int j = 0; j < right_side.get_cols(); j++){
      Real sum = 0;
      for(int k = 0; k < left_side.get_cols(); k++){
	sum += left_side.get(i ,k) * right_side.get(k,j);
      }
      m[i][j] = sum;
    }
  }
  return m;
}
Mat operator*(Real f, const Mat& right_side){
  Mat m(right_side);
  for(int i = 0; i < right_side.get_rows(); i++){
    for(int j = 0; j < right_side.get_cols(); j++){
      m[i][j] *= f;
    }
  }
  return m;
}
Mat operator+(const Mat& left_side, const Mat& right_side){
  assert(
	 right_side.get_cols() == left_side.get_cols()
	 &&
	 right_side.get_rows() == left_side.get_rows());
  Mat m(left_side);
  for(int i = 0; i < m.get_rows(); i++){
    for(int j = 0; j < m.get_cols(); j++){
      m[i][j] += right_side.get( i , j);
    }
  }
  return m;
}
//utils
Real Mat::get(int _r, int _c) const{
  assert(in_range(_r, _c));
  return arr[_r][_c];
}
int Mat::get_rows() const{
  return rows;
}
int Mat::get_cols() const{
  return cols;
}
Real& Mat::operator()(int _r, int _c){
  assert(in_range(_r, _c));
  return arr[_r][_c];
}
Real* Mat::operator[](int _ind){
  assert(in_range(_ind, 0));
  return arr[_ind];
}
bool Mat::in_range(int _r, int _c) const{
  bool ret_val = _r < rows;
  ret_val &= _r >= 0;
  ret_val &= _c < cols;
  ret_val &= _c >= 0;
  return ret_val;
}

//constructors and "rule of three" stuff
Mat::Mat(){
  cols = rows = 1;
  alloc_mat();
  arr[0][0] = 1;
}
Mat::Mat(int _cols, int _rows){
  cols = _cols;
  rows = _rows;
  alloc_mat();
}
Mat::Mat(const Mat& m){
  cols = m.get_cols();
  rows = m.get_rows();
  alloc_mat();
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      arr[i][j] = m.get(i , j);
    }
  }
}
Mat::~Mat(){
  dealloc_mat();
}
void Mat::dealloc_mat(){
  for(int i = 0; i < rows; i++){
    delete [] arr[i];
  }
  delete [] arr;
}
void Mat::alloc_mat(){
  arr = new Real*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new Real[cols];
  }
}
Mat& Mat::operator=(const Mat& m){
  if(this != &m){
    dealloc_mat();
    cols = m.get_cols();
    rows = m.get_rows();
    alloc_mat();
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
	arr[i][j] = m.get(i , j);
      }
    }
  }
  return *this;
}

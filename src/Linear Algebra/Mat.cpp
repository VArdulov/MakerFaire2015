#include <iostream>
#include "Mat.h"
using namespace std;


int main(){
  cout << "testing this shit" << endl;
  Mat m = random_mat(4, 4, 10);
  print(m);
  cout << endl << endl;
  m[0][0] = 69;
  print(m);
  return 0;
}
Mat Mat::inverse() const{
  //compute inverse using row reduction method
  //or something better if yoou know a better algorithm
  // don't use cramer's rule though, it's very unefficent
}
Mat Mat::pseudo_inverse() const{ //panrose psudo inverse
  
} 
//operator overloading stuff
Mat operator*(const Mat& right_side, const Mat& left_side){
  
}
Mat operator+(const Mat& right_side, const Mat& left_side){
  
}
Vector operator*(const Mat& right_side, const Vector& left_side){
  
}

//utils
Real Mat::get(int _r, int _c) const{
  return arr[_r][_c];
}
int Mat::get_rows() const{
  return rows;
}
int Mat::get_cols() const{
  return cols;
}
Real& Mat::operator()(int _r, int _c){
  return arr[_r][_c];
}
Real* Mat::operator[](int _ind){
  return arr[_ind];
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

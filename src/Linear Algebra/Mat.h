#ifndef _H_MAT
#define _H_MAT
#include "vector.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef float Real;

class Mat{
 public:
  Mat(); //V
  Mat(int _rows, int _cols); //V
  ~Mat(); //V
  Mat(const Mat& m); //V
  
  Mat& operator=(const Mat& other); //V

  Real& operator()(int _r, int _c); //V
  Real* operator[](int _ind);
  
  Real get(int _r, int _c) const; 
  int get_rows() const;
  int get_cols() const;
  bool in_range(int _r, int _c) const;

 private:
  void alloc_mat(); //V
  void dealloc_mat(); //V
  Real** arr; //V
  int rows,cols; //V
};

Mat operator*(const Mat& right_side, const Mat& left_side);
Mat operator*(Real f, const Mat& right_side);
Vector operator*(const Mat& right_side, const Vector& left_side);
Mat operator+(const Mat& right_side, const Mat& left_side);


void print(const Mat& m){
  for(int i = 0; i < m.get_rows(); i++){
    for(int j = 0; j < m.get_cols(); j++){
      printf("%7.2f", m.get(i , j));
    }
    printf("\n");
  }
}

Mat random_mat(int r, int c, int N){
  Mat M = Mat(c,r);
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      M[i][j] = rand() % N;
    }
  }
  return M;
}
Mat vector_to_matrix(const Vector& V){
  Mat m(V.size(), 1);
  for(int i = 0; i < m.get_rows(); i++){
    m[i][0] = V[i];
  }
  return m;
}
Vector matrix_to_vector(const Mat& m){
  assert(m.get_cols() == 1);
  Vector v(m.get_rows());
  for(int i = 0; i < m.get_rows(); i++){
    v[i] = m.get(i,0);
  }
  return v;
}
#endif

#ifndef _H_MAT
#define _H_MAT
#include "vector.h"
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
  Mat inverse() const;
  Mat pseudo_inverse() const;
 
  
  Real get(int _r, int _c) const; 
  int get_rows() const;
  int get_cols() const;
  

 private:
  void alloc_mat(); //V
  void dealloc_mat(); //V
  Real** arr; //V
  int rows,cols; //V
};

Mat operator*(const Mat& right_side, const Mat& left_side);
Vector operator*(const Mat& right_side, const Vector& left_side);
Mat operator+(const Mat& right_side, const Mat& left_side);


#define EXTRA_UTILS 1

#if EXTRA_UTILS
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
void print(const Mat& m){
  for(int i = 0; i < m.get_rows(); i++){
    for(int j = 0; j < m.get_cols(); j++){
      printf("%5.2f", m.get(i , j));
    }
    printf("\n");
  }
}
Mat random_mat(int r, int c, int N){
  Mat M = Mat(r,c);
  srand(time(NULL));
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      M[i][j] = rand() % N;
    }
  }
  return M;
}
#endif


#endif

#ifndef _H_MAT_REG
#define _H_MAT_REG

#include "vector.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <assert.h>

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

void print(const Mat& m);
Mat random_mat(int r, int c, int N);
Mat vector_to_matrix(const Vector& V);
Vector matrix_to_vector(const Mat& m);

#endif

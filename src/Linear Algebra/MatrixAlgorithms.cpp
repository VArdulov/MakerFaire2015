#include "MatrixAlgorithms.h"
#include "Mat.h"
#include "vector.h"
#include <stdio.h>
#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

#define DEBUG_MAT_ALGO 1

#if DEBUG_MAT_ALGO
int main(){
  printf("DEBUGING Matrix Algorithm \n");
  srand(time(NULL));
  
  Mat m = random_mat(1 + rand() % 4, 1 + rand() % 4, 10);
  print(m);
  cout << endl << endl;
  swop_rows(&m, 0, rand() % m.get_rows());
  print(m);
  return 0;
}
#endif

void row_reduce(Mat* m){
  
}
void swop_rows(Mat* m, int r1, int r2){
  Real temp;
  for(int i = 0; i < m->get_cols(); i++){
    temp = m->get(r1, i);
    (*m)[r1][i] = m->get(r2, i);
    (*m)[r2][i] = temp;
  }
}
void multiply_row(Mat* m, int r1, Real alph){
  for(int i = 0; i < m->get_cols(); i++){
    (*m)[r1][i] *= alph;
  }
}
void multiply_and_add_row(Mat* m, int r1, int r2, Real alph){
  for(int i = 0; i < m->get_cols(); i++){
    (*m)[r2][i] += alph * (*m)[r1][i];
  }
}

Mat row_reduce(const Mat& M){
  Mat m_temp(M);
  row_reduce(&m_temp);
  return m_temp;
}
Mat swop_rows(const Mat& M, int row1, int row2){
  Mat m_temp(M);
  swop_rows(&m_temp, row1, row2);
  return m_temp;
}
Mat multiply_row(const Mat& M, int row, Real alph){
  Mat m_temp(M);
  multiply_row(&m_temp, row, alph);
  return m_temp;
}
Mat multiply_and_add_row(const Mat& M, int row_src, int row_dest, Real alph){
  Mat m_temp(M);
  multiply_and_add_row(&m_temp, row_src, row_dest, alph);
  return m_temp;
}
Mat Tr(const Mat& m){
  Mat tr_m(m.get_cols(), m.get_rows());
  for(int i = 0; i < m.get_cols(); i++){
    for(int j = 0; j < m.get_rows(); j++){
      tr_m[i][j] = m.get(j, i);
    }
  }
  return tr_m;
}

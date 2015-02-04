#include "MatrixAlgorithms.h"
#include "Mat.h"
#include "vector.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <assert.h>

using std::cout;
using std::endl;

#define DEBUG_MAT_ALGO 1

#if DEBUG_MAT_ALGO
int main(){
  printf("DEBUGING Matrix Algorithm \n");
  srand(time(NULL));
  
  Mat m = random_mat(3, 3, 10);
  print(m);
  cout << endl << endl;
  Mat m2 = pseudo_inverse(m);
  print(m2);
  cout << endl;
  print(m2 * m);
  return 0;
}
#endif

Vector solve_linear_equation(Mat* m, Vector* v){ 
  Mat& M = *m; Vector& V = *v;
  
  assert(M.get_rows() == V.size());
  Mat aux_mat(V.size(), M.get_cols() + 1);
  for(int i = 0; i < M.get_rows(); i++){
    for(int j = 0; j < M.get_cols(); j++){
      aux_mat[i][j] = M[i][j];
    }
    aux_mat[i][M.get_cols()] = V[i];
  }
  cout << endl << "Aux MAt" << endl;
  row_reduce(aux_mat);
  
  Vector solution(M.get_cols());
  for(int i = 0; i < M.get_cols(); i++){
    solution[i] = aux_mat[i][M.get_cols()];
  }
  return solution;
}


Vector solve_linear_equation(const Mat& M, const Vector& v){
  Mat temp_m(M);
  Vector temp_v(v);
  return solve_linear_equation(*temp_m, *temp_v);
}
Mat Inverse(const Mat& M){
  assert(M.get_rows() == M.get_cols()); //check if matrix is square
  Mat aux_mat(M.get_rows(),2 * M.get_cols());

  
  for(int i = 0; i < M.get_rows(); i++){
    for(int j = 0; j < M.get_cols(); j++){
      aux_mat[i][j] = M.get(i, j);
      aux_mat[i][j + M.get_cols()] = (i == j)? 1 : 0;
    }
  }
  /*  cout << endl << "Aux Matrix: " << endl;
  print(aux_mat);
  cout << endl;*/
  row_reduce(&aux_mat);
  Mat ret_mat(M.get_rows(), M.get_cols());
  for(int i = 0; i < M.get_rows(); i++){
    for(int j = 0; j < M.get_cols(); j++){
      ret_mat[i][j] = aux_mat[i][j + M.get_cols()];
    }
  }
  return ret_mat;
}

Mat pseudo_inverse(const Mat& A){
  return (Tr(A) * Inverse(A * Tr(A)) );
}

void row_reduce(Mat* m){
  Mat& M = *m; //to make syntax easier
  for(int row = 0; row < M.get_rows() && row < M.get_cols(); row++){
    int temp_row = row;
    while(temp_row < M.get_rows()){
      if(M[temp_row][row] != 0){
	goto FOUND_A_NON_ZERO;
      }
      temp_row++;
    }
    continue; //basically means that the whole colom is full of 0's
             //i.e no pivot point here 
  FOUND_A_NON_ZERO:
    swop_rows(m, row, temp_row);
    //scale everything
    multiply_row(m, row, 1.0 / M[row][row]);
    //in this part we reduce from all other rows;
    for(int i = 0; i < M.get_rows(); i++){
      if(i != row)
	multiply_and_add_row(m, row, i, -M[i][row]); 
    }
  }
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

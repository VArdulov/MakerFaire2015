#ifndef _H_MATRIX_ALGORITHMS
#define _H_MATRIX_ALGORITHMS

#include "Mat.h"
#include "vector.h"

typedef float Real;

Mat row_reduce(const Mat& M);
Mat swop_rows(const Mat& M, int row1, int row2);
Mat multiply_row(const Mat& M, int row, Real alph);
Mat multiply_and_add_row(const Mat& M, int row_src, int row_dest, Real alph);

Mat Tr(const Mat& M); //Transpose
Mat Inverse(const Mat& M);
Mat pseudo_inverse();

void swop_rows(Mat* );

Mat get_identity(int n);
Mat get_zeros(int n);
Mat random_matrix();

#endif

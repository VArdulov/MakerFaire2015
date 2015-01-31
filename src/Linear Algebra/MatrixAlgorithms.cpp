#include "MatrixAlgorithms.h"
#include "Mat.h"
#include "vector.h"
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

#define DEBUG_MAT_ALGO 1

#if DEBUG_MAT_ALGO
int main(){
  printf("DEBUGING Matrix Algorithm \n");
  
  Mat m = random_mat(2, 3, 10);
  print(m);
  cout << endl;
  print(Tr(m));
  
  return 0;
}
#endif
Mat Tr(const Mat& m){
  Mat tr_m(m.get_cols(), m.get_rows());

  for(int i = 0; i < m.get_cols(); i++){
    for(int j = 0; j < m.get_rows(); j++){
      //    cout << i << " pre " << j << endl;
      tr_m[i][j] = m.get(j, i);
      //      cout << "post" << endl;
    }
  }
  return tr_m;
}

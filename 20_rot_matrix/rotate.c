#include<stdio.h>
#include<stdlib.h>

void rotate(char matrix[10][10]){
  char tmp[10][10];
  int i,j,k;
  for (i=0; i<10; i++){
    j=0;
      for (k=9; k>=0; k--){
        tmp[i][j]=matrix[k][i];
        j++;
      }
  }
   for (i=0; i<10; i++){ // paste tmp on 10x10 result
    for (j=0; j<10; j++){
      matrix[i][j] = tmp[i][j];
    }
  }
}

#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array, size_t n);

int main () {
  int case1[] = {};
  int case2[] = {-5, 0, 5};
  int case3[] = {1, 6, 10, -1, -3, 4, 45, 50, 53, 2};
  int case4[] = {-100, -50, -1, -2};
  int case5[] = {8, 8, 8};
  int case6[] = {0, 1, 2, 5, 10, 99};
  if(maxSeq(case1, 0) != 0) {
    printf("Failed on NULL\n");
    exit(EXIT_FAILURE);
  }
  if(maxSeq(case2, 3) != 3) {
    printf("Failed on -5 0 5\n");
    exit(EXIT_FAILURE);
  }
  if(maxSeq(case3, 10) != 5) {
    printf("Failed on {1, 6, 10, -1, -3, 4, 45, 50, 53, 2}\n");
    exit(EXIT_FAILURE);
  }
  if(maxSeq(case4, 4) != 3) {
    printf("Failed on -100 -50 -1 -2\n");
    exit(EXIT_FAILURE);
  }
  if(maxSeq(case5, 3) != 1) {
    printf("Failed on 8 8 8\n");
    exit(EXIT_FAILURE);
  }
  if(maxSeq(case6, 6) != 6) {
    printf("Failed on 1 0 2 5 10 99\n");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}

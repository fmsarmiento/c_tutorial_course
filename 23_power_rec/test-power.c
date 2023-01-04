#include<stdlib.h>
#include<stdio.h>
unsigned power (unsigned x, unsigned y);

int main(void) {
  // try: pospos, negneg, posneg, 0pos, 0neg, 00
  if(power(2,2) != 4) {
    exit(EXIT_FAILURE);
  }
  if(power(-2,2) != 4) {
    exit(EXIT_FAILURE);
  }
  if(power(0,1) != 0) {
    exit(EXIT_FAILURE);
  }
  if(power(-4,1) != (-4)) {
    exit(EXIT_FAILURE);
  }
  if(power(0,0) != 1) {
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}

#include <stdio.h>                     
#include <stdlib.h>

unsigned power(unsigned x, unsigned y){
  unsigned out = 1;
  if(y==0)  return 1;
  if(y==1)  return x;
  out = x * power(x, y-1);
  return out;
}

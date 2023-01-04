#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n) {
  int maxLen = 1;
  int currPt = 1;
  int i;
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
      return 1;
  }
  for (i=1; i < n; ++i) {
    if (array[i] > array[i-1]) {
      currPt += 1;
    } else {
      currPt = 1;
    }
    if (currPt > maxLen) {
      maxLen = currPt;
    }
  }

  return maxLen;
}

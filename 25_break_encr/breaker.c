#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getCommon(int *freqCommon, FILE *f) {
  int c;
  while((c=fgetc(f)) != EOF) {
    if(isalpha(c)) {
      c = tolower(c); //lowercase characters
      c = c - 'a'; // convert to char
      freqCommon[c] = freqCommon[c]+1; // count+1
    }
  }
}

int commonIndex(int * freqCommon) {
  int max = freqCommon[0];
  int idx = 0;
  for(int i=0; i<26; i++) {
    if(freqCommon[i] > max) {
      max = freqCommon[i];
      idx = i;
    }
  }
  return idx;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Wrong amount of arguments.\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("File not existing.\n");
    return EXIT_FAILURE;
  }
  int commonArray[26] = {0};
  getCommon(commonArray, f);
  int idx = commonIndex(commonArray);
  int key = (idx + 'a' - 'e' + 26)%26;
  printf("%d\n", key);
}

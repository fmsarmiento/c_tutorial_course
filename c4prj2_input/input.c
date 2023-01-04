#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"deck.h"
#include"cards.h"
#include"future.h"
#include"input.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards = 0;
  int i = 0;
  char * backslashN = "\n";
  char questionMark = '?';
  while(1==1) {
    if (*(str+i) == questionMark) { // if ? is found, count digits of n in ?n
      size_t index;
      int j = 1;
      while (isdigit(*(str+i+j))) {
	    j++;
      }
      char tmp[j];
      for (int k=0; k<j-1; k++) {
	    tmp[k] = *(str+i+k+1);
      }
      tmp[j-1] = '\0';
      int n = atoi(tmp);
      index = (size_t)n;
      card_t * ptr = add_empty_card(deck);
      add_future_card(fc, index, ptr);
      i+=j;
    }
    else if (isalnum(*(str+i))) { // if it is a known card (not ?)
      card_t c = card_from_letters(*(str+i), *(str+i+1));
      add_card_to(deck, c);
      i+=2;
    }
    else if (strcmp(str+i, backslashN)==0) break; // if we finished combing through the end of the hand, break
    else i++; // increment
  }
  if (deck->n_cards < 5) return NULL;
  return deck;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
  deck_t ** out = NULL;
  char * line = NULL;
  size_t sizeIn = 0;
  int i=0;
  while(getline(&line, &sizeIn, f) > 0) {
    (*n_hands)++;
    out = realloc(out, *n_hands * sizeof(**out));
    deck_t * deck = hand_from_string(line, fc);
    out[i] = deck;
    free(line);
    line = NULL;
    i = i + 1;
  }
  free(line);
  return out;
}

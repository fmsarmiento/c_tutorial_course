#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  size_t i=0;
  print_card(*hand->cards[i++]);
  for(int i=1;i<(hand->n_cards); i++) {
    printf(" ");
    print_card(*hand->cards[i++]);
  }
}

int deck_contains(deck_t * d, card_t c) {
  for(int i=0;i<d->n_cards;i++) {
    if(c.value==d->cards[i]->value && c.suit==d->cards[i]->suit) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  for(size_t j = 0;j<d->n_cards;j++) { // for every card in d
    card_t * tmp = d->cards[j]; // temp variable; for swapping
    size_t n=(random()*random()) % d->n_cards; // get a random number w/ len(n_cards)
    d->cards[j]=d->cards[n]; //swap
    d->cards[n]=tmp; //swap
  }
}

void assert_full_deck(deck_t * d) {
  unsigned deck[52]={0};
  unsigned i;
  for(i=0;i<52;i++){
    if(deck_contains(d,card_from_num(i))){ // does deck contain card?
      deck[i]++;
    }
  }
  for(i=0;i<52;i++){
    if(deck[i]>1){
      assert(deck[i]>1); // perform assert on each card
    }
  }
}

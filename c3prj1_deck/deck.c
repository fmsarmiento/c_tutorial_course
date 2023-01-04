#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  for(int i=0;i<hand->n_cards;i++) {
    print_card(*hand->cards[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t * currentCard = NULL;
  for(int i=0;i<d->n_cards;i++) {
    currentCard = d->cards[i];
    if(c.value == currentCard->value && c.suit == currentCard->suit) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  for(int i=0;i<d->n_cards;i++) {
    card_t * swap = d->cards[i];
    int n=(random()*random()) % d->n_cards;
    d->cards[i] = d->cards[n];
    d->cards[n] = swap;
  }
}

void assert_full_deck(deck_t * d) {
  for(int i=0;i<d->n_cards;i++) {
    assert(deck_contains(d, card_from_num(i)));
  }
}

void add_card_to(deck_t * deck, card_t c){
  deck->n_cards++;
  deck->cards = realloc(deck->cards,(deck->n_cards)*sizeof(*(deck->cards)));
  deck->cards[deck->n_cards-1] = NULL;
  deck->cards[deck->n_cards-1] = realloc(deck->cards[deck->n_cards-1], sizeof(*(deck->cards[deck->n_cards-1])));
  deck->cards[deck->n_cards-1]->suit = c.suit;
  deck->cards[deck->n_cards-1]->value = c.value;
}

card_t * add_empty_card(deck_t * deck){
  card_t * temp = malloc(sizeof(*temp));
  temp->suit = 0;
  temp->value = 0;
  deck->n_cards++;
  deck->cards = realloc(deck->cards, (deck->n_cards)*sizeof(*(deck->cards)));
  deck->cards[deck->n_cards-1] = temp;
  return temp;
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
  card_t currCard;
  deck_t * out = malloc(sizeof(*out));
  out->n_cards = 0;
  out->cards = NULL;
  int cond = 0;
  for(unsigned i=0; i<52; i++){
    currCard = card_from_num(i);
    cond = deck_contains(excluded_cards, currCard);
    if(cond==0){
      add_card_to(out, currCard);
    }
  }
  return out;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t * dExclude = malloc(sizeof(*dExclude));
  dExclude->n_cards = 0;
  dExclude->cards = malloc(sizeof(*dExclude->cards));
  for (size_t h=0; h<n_hands; h++) {
    for (size_t c=0; c<hands[h]->n_cards; c++) {
      add_card_to(dExclude, *hands[h]->cards[c]);
    }
  }
  dExclude = make_deck_exclude(dExclude);
  return dExclude;
}

void free_deck(deck_t * deck){
  for(size_t i=0; i<deck->n_cards; i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}

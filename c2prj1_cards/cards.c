#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value<=14);
  assert(c.suit>=0 && c.suit<=3);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
    case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
    case FULL_HOUSE: return "FULL_HOUSE";
    case FLUSH: return "FLUSH";
    case STRAIGHT: return "STRAIGHT";
    case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
    case TWO_PAIR: return "TWO_PAIR";
    case PAIR: return "PAIR";
    case NOTHING: return "NOTHING";
  }
  return "";
}

char value_letter(card_t c) {
  if(c.value >=2 && c.value < 10) { 
    return '0' + c.value;
  }
  switch(c.value) {
    case 14: return 'A';
    case 10: return '0';
    case 11: return 'J';
    case 12: return 'Q';
    case 13: return 'K';
  }
  return 'x';
}


char suit_letter(card_t c) {
  switch(c.suit) {
    case SPADES: return 's';
    case HEARTS: return 'h';
    case DIAMONDS: return 'd';
    case CLUBS: return 'c';
    case NUM_SUITS: return 'x';
  }
  return 'x';
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  // value
  if(value_let >= '2' && value_let <= '9') {
    temp.value = value_let - '0';
  } else {
      switch(value_let) {
      case '0': temp.value = 10; break;
      case 'J': temp.value = 11; break;
      case 'Q': temp.value = 12; break;
      case 'K': temp.value = 13; break;
      case 'A': temp.value = 14; break;
      default: temp.value = -1; break;
      }
    }
  switch(suit_let) {
  case 's': temp.suit = SPADES; break;
  case 'd': temp.suit = DIAMONDS; break;
  case 'h': temp.suit = HEARTS; break;
  case 'c': temp.suit = CLUBS; break;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  assert(c >= 0 && c < 53);
  card_t temp;
  switch(c/13) {
  case SPADES: temp.suit = SPADES; break;
  case HEARTS: temp.suit = HEARTS; break;
  case DIAMONDS: temp.suit = DIAMONDS; break;
  case CLUBS: temp.suit = CLUBS; break;
  }
  int rem = c % 13;
  if(rem >= 2 && rem <= 10) {
    temp.value = rem;
  } else {
    switch(rem) {
    case 1: temp.value = 14; break;
    case 0: temp.value = 13; break;
    case 11: temp.value = 11; break;
    case 12: temp.value = 12; break;
    }
  }
  return temp;
}

#include "cards.h"
#include<stdio.h>
int main(void) {
  card_t test;
  test.value = 5;
  test.suit = 0;
  // 5 of spades
  assert_card_valid(test);
  printf("validated.\n");
  printf("Card created is ");
  print_card(test);
  printf("\n");
  test = card_from_letters('A','s'); //ace of spades
  print_card(test);
  printf("\n");
  test = card_from_num(0); // ace of spades
  print_card(test);
  printf("\n");
			   
}

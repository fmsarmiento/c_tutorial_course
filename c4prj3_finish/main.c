#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

size_t who_won(deck_t ** hands, size_t n) { // finds who won
    size_t winner = 0;
    deck_t * winningDeck = hands[0];
    for (size_t i = 1; i < n; i++) {
        int result = compare_hands(winningDeck, hands[i]);
        if (result == 0) winner = n;
        if (result < 0 ) {
            winner = i;
            winningDeck = hands[i];
        }
    }
    return winner;
}

void print_results(unsigned int * results, unsigned int n, unsigned int total) {
    for(size_t i=0;i<n;i++) {
        printf("Hand %zu won %u / %u times (%.2f%%)\n", i, results[i], total, (float) results[i] / total * 100);
    }
    printf("And there were %u ties\n", results[n]);
}

int main(int argc, char ** argv) {
    if (argc != 2 && argc != 3) return EXIT_FAILURE; // no inputs
    unsigned int tries = 10000;
    if (argc == 3) tries = atoi(argv[2]);
    FILE * f = fopen(argv[1], "r");
    size_t handCtr = 0;
    future_cards_t * fc = malloc(sizeof(*fc));
    fc->decks = NULL;
    fc->n_decks = 0;
    deck_t ** readHand = read_input(f, &handCtr, fc);
    fclose(f);
    deck_t * deck_left = build_remaining_deck(readHand, handCtr);
    unsigned int * ctrWon = calloc(handCtr + 1, sizeof(*ctrWon));
    for(int i = 0; i < tries; i++) {
        shuffle(deck_left);
        future_cards_from_deck(deck_left, fc);
        unsigned int winner = who_won(readHand, handCtr);
        ctrWon[winner]++;
    }
    print_results(ctrWon, handCtr, tries);
    free(ctrWon);
    free_deck(deck_left);
    for (int i = 0; i < handCtr; i++) {
        free_deck(readHand[i]);
    }
    free(readHand);
    for (int i = 0; i < fc->n_decks; i++) {
        free(fc->decks[i].cards);
    }
    free(fc->decks);
    free(fc);
    return EXIT_SUCCESS;

}

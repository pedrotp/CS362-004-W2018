// Test for the shuffle() function inside dominion.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

// Colors for test results
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

int compare(const int* a, const int* b);

int main () {

  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  int ogDeck[10];
  int eq;

  initializeGame(2, k, 1234, &G);

  int i=0;
  printf ("\nTesting shuffle():\n\n");

  // set both player's decks to be equal
  for (i = 0; i < G.deckCount[0]; i++) {
    G.deck[1][i] = G.deck[0][i];
    // and save the original deck for comparison
    ogDeck[i] = G.deck[0][i];
  }
  G.deckCount[1] = G.deckCount[0];

  // shuffle both decks
  shuffle(0, &G);
  shuffle(1, &G);

  // make sure both decks have the same number of cards
  if (G.deckCount[1] != G.deckCount[1]) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Both shuffled decks have the same number of cards\n");

  // make sure both shuffled decks are different from each other
  eq = 1;
  for (i = 0; i < G.deckCount[0]; i++) {
    if (G.deck[1][i] != G.deck[0][i]) {
      eq = 0;
    }
  }
  if (eq) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Both shuffled decks are different from each other\n");

  // make sure both shuffled decks are different from the original deck
  eq = 1;
  for (i = 0; i < G.deckCount[0]; i++) {
    if (G.deck[1][i] != G.deck[0][i]) {
      eq = 0;
    }
  }
  if (eq)  {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Both shuffled decks are different from the original pre-shuffle order\n");

  // make sure both shuffled decks have the same cards as the original
  qsort ((void*)(G.deck[0]), G.deckCount[0], sizeof(int), compare);
  qsort ((void*)(G.deck[1]), G.deckCount[1], sizeof(int), compare);

  eq = 1;
  for (i = 0; i < G.deckCount[0]; i++) {
    if (G.deck[1][i] != G.deck[0][i]) {
      eq = 0;
    }
  }
  if (!eq) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Both shuffled decks have the same set of cards\n\n");

  return 0;

}

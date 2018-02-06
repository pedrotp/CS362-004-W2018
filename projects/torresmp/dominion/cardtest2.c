// Test for the adventurer card inside dominion.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

// Colors for test results
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

int main () {

  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  int preDeck, preHand, preDiscard;

  printf ("\nTesting adventurer:\n\n");

  initializeGame(2, k, 1234, &G);
  G.hand[0][1] = adventurer;

  preDeck = G.deckCount[0];
  preHand = G.handCount[0];
  preDiscard = G.discardCount[0];

  cardEffect(adventurer, -1, -1 , -1, &G, 1, NULL);

  // hand has three more cards
  if (G.handCount[0] != preHand + 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("After adding two cards and discarding adventurer, +1 cards in player's hand\n");

  // deck has three fewer cards
  if (G.deckCount[0] != preDeck - 2) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Two cards removed from the player's deck\n");

  // one additional card in the played pile
  if (G.discardCount[0] != preDiscard + 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("One card added to discard pile\n");

  // adventurer card is now in the discard pile
  if (G.discard[0][G.discardCount[0] - 1] != adventurer) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("The last card discarded is adventurer\n\n");

  return 0;

}

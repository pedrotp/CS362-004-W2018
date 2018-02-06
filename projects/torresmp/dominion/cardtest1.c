// Test for the smithy card inside dominion.c

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
  int preDeck, preHand, prePlayed;

  printf ("\nTesting smithy:\n\n");

  initializeGame(2, k, 1234, &G);
  G.hand[0][1] = smithy;

  preDeck = G.deckCount[0];
  preHand = G.handCount[0];
  prePlayed = G.playedCardCount;

  cardEffect(smithy, -1, -1 , -1, &G, 1, NULL);

  // hand has three more cards
  if (G.handCount[0] != preHand + 2) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("After adding three cards and discarding one, +2 cards in player's hand\n");

  // deck has three fewer cards
  if (G.deckCount[0] != preDeck - 3) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Three cards removed from the player's deck\n");

  // one additional card in the played pile
  if (G.playedCardCount != prePlayed + 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("One card added to played cards pile\n");

  // smithy card is now in the played pile
  if (G.playedCards[G.playedCardCount - 1] != smithy) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("The last card played is smithy\n\n");

  return 0;

}

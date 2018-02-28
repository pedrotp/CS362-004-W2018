// Test for the great hall card inside dominion.c

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

  printf ("\nTesting great hall:\n\n");

  initializeGame(2, k, 1234, &G);
  G.hand[0][1] = great_hall;

  preDeck = G.deckCount[0];
  preHand = G.handCount[0];
  prePlayed = G.playedCardCount;

  cardEffect(great_hall, -1, -1 , -1, &G, 1, NULL);

  // hand has same number of cards
  if (G.handCount[0] != preHand) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("After adding a cards and discarding the played card, same number of cards in player's hand\n");

  // deck has one fewer card1
  if (G.deckCount[0] != preDeck - 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("One card removed from the player's deck\n");

  // one additional card in the played pile
  if (G.playedCardCount != prePlayed + 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("One card added to played cards pile\n");

  // council room card is now in the played pile
  if (G.playedCards[G.playedCardCount - 1] != great_hall) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("The last card played is the great hall\n");

  // player has an an additional action for this turn
  if (G.numActions != 2) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Number of actions for this turn increased to 2\n\n");

  return 0;

}

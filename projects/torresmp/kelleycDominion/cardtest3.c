// Test for the council room card inside dominion.c

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

  printf ("\nTesting council room:\n\n");

  initializeGame(2, k, 1234, &G);
  G.hand[0][1] = council_room;

  preDeck = G.deckCount[0];
  preHand = G.handCount[0];
  prePlayed = G.playedCardCount;

  cardEffect(council_room, -1, -1 , -1, &G, 1, NULL);

  // hand has four more cards
  if (G.handCount[0] != preHand + 3) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("After adding four cards and discarding one, +3 cards in player's hand\n");

  // deck has four fewer cards
  if (G.deckCount[0] != preDeck - 4) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Four cards removed from the player's deck\n");

  // one additional card in the played pile
  if (G.playedCardCount != prePlayed + 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("One card added to played cards pile\n");

  // council room card is now in the played pile
  if (G.playedCards[G.playedCardCount - 1] != council_room) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("The last card played is council room\n");

  // player has an extra buy for this turn
  if (G.numBuys != 2) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Number of buys for this turn increased to 2\n\n");

  return 0;

}

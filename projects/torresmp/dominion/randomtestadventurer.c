// Random test for the adventurer card inside dominion.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "rngs.h"

// number of test cycles to run
#define NUMTESTS 10000000

int main () {

  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  int i, seed, numPlayers, handPos, player, preDeck, preHand, preDiscard;
  int test1_f = 0, test1_p = 0, test2_f = 0, test2_p = 0, test3_f = 0, test3_p = 0, test4_f = 0, test4_p = 0;
  time_t t;
  srand((unsigned) time(&t));

  printf ("\n**ADVENTURER TEST RESULTS**\n\n");

  for (i = 0; i < NUMTESTS; i++) {

    seed = rand();
    numPlayers = (rand() % 5) + 2; // random number of players from 2 to 6
    handPos = rand() % 5; // random hand position 0 to 5
    player = rand() % numPlayers; // random player plays the card
    initializeGame(numPlayers, k, seed, &G);
    G.hand[player][handPos] = adventurer; // place adventurer in the hand position generated

    // record values before playing adventurer
    preDeck = G.deckCount[player];
    preHand = G.handCount[player];
    preDiscard = G.discardCount[player];

    // play adventurer
    cardEffect(adventurer, -1, -1 , -1, &G, handPos, NULL);

    // hand has one more card
    if (G.handCount[player] != preHand + 1) {
      test1_f++;
    } else {
      test1_p++;
    }

    // deck has two fewer cards
    if (G.deckCount[player] != preDeck - 2) {
      test2_f++;
    } else {
      test2_p++;
    }

    // one additional card in the played pile
    if (G.discardCount[player] != preDiscard + 1) {
      test3_f++;
    } else {
      test3_p++;
    }

    // adventurer card is now in the discard pile
    if (G.discard[player][G.discardCount[player] - 1] != adventurer) {
      test4_f++;
    } else {
      test4_p++;
    }

  }

  // print test results
  printf("TEST 1: 'After adding two cards and discarding adventurer, +1 cards in player's hand'\n");
  printf("FAILED -- %d (%.2f%%)\n", test1_f, (float)(test1_f * 100) / (float)NUMTESTS);
  printf("PASSED -- %d (%.2f%%)\n\n", test1_p, (float)(test1_p * 100) / (float)NUMTESTS);

  printf("TEST 2: 'Two cards are removed from the player's deck'\n");
  printf("FAILED -- %d (%.2f%%)\n", test2_f, (float)(test2_f * 100) / (float)NUMTESTS);
  printf("PASSED -- %d (%.2f%%)\n\n", test2_p, (float)(test2_p * 100) / (float)NUMTESTS);

  printf("TEST 3: 'One card added to discard pile'\n");
  printf("FAILED -- %d (%.2f%%)\n", test3_f, (float)(test3_f * 100) / (float)NUMTESTS);
  printf("PASSED -- %d (%.2f%%)\n\n", test3_p, (float)(test3_p * 100) / (float)NUMTESTS);

  printf("TEST 4: 'The last card discarded is adventurer'\n");
  printf("FAILED -- %d (%.2f%%)\n", test4_f, (float)(test4_f * 100) / (float)NUMTESTS);
  printf("PASSED -- %d (%.2f%%)\n\n", test4_p, (float)(test4_p * 100) / (float)NUMTESTS);

  return 0;

}

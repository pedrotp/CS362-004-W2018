// Test for the gainCard() function inside dominion.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

// Colors for test results
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

int cardCount(int* pile, int size, int cardType) {
  int i, count = 0;
  for (i = 0; i < size; i++) {
    if (pile[i] == cardType) count++;
  }
  return count;
}

int main () {

  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  initializeGame(2, k, 1234, &G);

  int i=0, temp, res, s, pre, post;
  printf ("\nTesting gainCard():\n\n");

  // -1 if no cards of that type in supply pile
  temp = G.supplyCount[smithy];
  G.supplyCount[smithy] = 0;
  res = 0;
  for (i = 0; i < 3; i++) { // once for each flag
    res += gainCard(smithy, &G, i, 0);
  }
  G.supplyCount[smithy] = temp;
  s = G.supplyCount[smithy]; // save original smithy supply

  if (res != -3) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Function returns -1 if no cards of selected type available\n");

  pre = cardCount(G.hand[0], G.handCount[0], smithy);
  temp = G.handCount[0];
  gainCard(smithy, &G, 2, 0);
  post = cardCount(G.hand[0], G.handCount[0], smithy);

  // player's hand gains a card of the specified type (flag 2)
  if (post - pre != 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Flag 2: number of specified cards in player's hand increase by 1\n");

  // handCount for player goes up by 1 after card is gained (flag 2)
  if (G.handCount[0] - temp != 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Flag 2: total number of cards in player's hand increases by 1\n");

  pre = cardCount(G.deck[0], G.deckCount[0], smithy);
  temp = G.deckCount[0];
  gainCard(smithy, &G, 1, 0);
  post = cardCount(G.deck[0], G.deckCount[0], smithy);

  // player's deck gains a card of the specified type (flag 1)
  if (post - pre != 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Flag 1: number of specified cards in player's deck increase by 1\n");

  // handCount for player goes up by 1 after card is gained (flag 2)
  if (G.deckCount[0] - temp != 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Flag 1: total number of cards in player's deck increases by 1\n");

  pre = cardCount(G.discard[0], G.discardCount[0], smithy);
  temp = G.discardCount[0];
  gainCard(smithy, &G, 0, 0);
  post = cardCount(G.discard[0], G.discardCount[0], smithy);

  // player's discard pile gains a card of the specified type (flag 0)
  if (post - pre != 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Flag 0: number of specified cards in player's discard pile increase by 1\n");

  // handCount for player goes up by 1 after card is gained (flag 2)
  if (G.discardCount[0] - temp != 1) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Flag 0: total number of cards in player's discard pile increases by 1\n");

  // supplyCount goes down by 1 each time a card is gained
  if (s - G.supplyCount[smithy] != 3) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Supply count for the specified type decreases by 1 for every card gained\n\n");


  return 0;

}

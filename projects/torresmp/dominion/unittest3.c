// Test for the isGameOver() function inside dominion.c

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
  int over, temp;

  printf ("\nTesting isGameOver():\n\n");

  initializeGame(2, k, 1234, &G);

  // if no 3 piles are depleted, and the province pile is not depleted, the game is not over
  over = isGameOver(&G);
  if (over) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Game is not over if neither condition has been met\n");

  // the game ends when the are no more province cards in the supply pile
  temp = G.supplyCount[province];
  G.supplyCount[province] = 0;
  over = isGameOver(&G);
  G.supplyCount[province] = temp; // reset province count

  if (!over) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Game ends when the Province card supply is at 0\n");

  // the game ends when any three card supplies are depleted
  G.supplyCount[adventurer] = 0;
  G.supplyCount[gardens] = 0;
  G.supplyCount[village] = 0;
  over = isGameOver(&G);

  if (!over) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("Game ends when three card supply piles go to 0\n\n");

  return 0;

}

// Test for the supplyCount() function inside dominion.c

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

  printf ("\nTesting supplyCount():\n\n");

  initializeGame(2, k, 1234, &G);

  if (supplyCount(adventurer, &G) != G.supplyCount[adventurer]) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("The function returns the appropriate amount after initializing\n");

  G.supplyCount[adventurer]++;

  if (supplyCount(adventurer, &G) != G.supplyCount[adventurer]) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("The function returns the appropriate amount after increasing\n");

  G.supplyCount[adventurer]--;

  if (supplyCount(adventurer, &G) != G.supplyCount[adventurer]) {
    printf(RED "FAILED -- ");
  } else {
    printf(GREEN "PASSED -- ");
  }
  printf("The function returns the appropriate amount after decreasing\n\n");

  return 0;

};

// int supplyCount(int card, struct gameState *state) {
//   return state->supplyCount[card];
// }

// The below code can be used to check

// // test initial supply values for 2 to 8 players
// for (i = 2; i < 7; i++) {
//
//
//   // 60 copper - 7 for each player's hand
//   if (supplyCount(copper, &G) != 60 - (i*7)) correct = 0;
//
//   // 30 gold
//   if (supplyCount(gold, &G) != 30) correct = 0;
//
//   // 40 silver
//   if (supplyCount(silver, &G) != 40 * (i-1)) correct = 0;
//
//   // 10 curse cards for each player beyond the first
//   if (supplyCount(curse, &G) != 10 * (i-1)) correct = 0;
//
//   // 8 province cards for 2 players, 12 for 3 and 4, and +3 for each player above 4
//   if (i == 2) {
//     if (supplyCount(province, &G) != 8) correct = 0;
//   } else if (i < 5) {
//     if (supplyCount(province, &G) != 12) correct = 0;
//   } else {
//     if (supplyCount(province, &G) != 12 + (3 * (i-4))) correct = 0;
//   }
//
//   // 8 victory cards for 2 players, 12 for more
//   if (i == 2) {
//     if (supplyCount(estate, &G) != 8) correct = 0;
//   } else {
//     if (supplyCount(estate, &G) != 12) correct = 0;
//   }
//
//   if (i == 2) {
//     if (supplyCount(duchy, &G) != 8) correct = 0;
//   } else {
//     if (supplyCount(duchy, &G) != 12) correct = 0;
//   }
//
//   if (i == 2) {
//     if (supplyCount(gardens, &G) != 8) correct = 0;
//   } else {
//     if (supplyCount(gardens, &G) != 12) correct = 0;
//   }
//
//   // 10 of each remaining selected kingdom card
//   if (supplyCount(adventurer, &G) != 10) correct = 0;
//   if (supplyCount(mine, &G) != 10) correct = 0;
//   if (supplyCount(smithy, &G) != 10) correct = 0;
//   if (supplyCount(village, &G) != 10) correct = 0;
//   if (supplyCount(minion, &G) != 10) correct = 0;
//   if (supplyCount(tribute, &G) != 10) correct = 0;
//   if (supplyCount(cutpurse, &G) != 10) correct = 0;
//   if (supplyCount(embargo, &G) != 10) correct = 0;
//   if (supplyCount(sea_hag, &G) != 10) correct = 0;
//   printSupply(&G);
// }
//
// if (!correct) {
//   printf(RED "FAILED -- ");
// } else {
//   printf(GREEN "PASSED -- ");
// }
// printf("The supply has the correct number of cards for each type\n");

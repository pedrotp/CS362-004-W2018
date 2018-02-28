/************************************************************************
** Cody Kelley
** CS362 - Winter 2018
**
** cardtest3.c
**
** Include the following lines in your makefile:
**
** cardtest3: cardtest3.c dominion.o rngs.o
**      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
**
** This tests card: village
**
** Card effects: +1 card, +2 actions
** Test for +1 card, +2 actions, card must come from own pile, piles
** should contain correct counts (hand, deck, played), no other player
** state should change, supply counts should not change.
*************************************************************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//change NOISY_TEST to 0 to remove printfs
#define NOISY_TEST 1

int assertTrue(const int a, const int b) {

        if (a == b) {

#if (NOISY_TEST == 1)
                printf("PASSED!\n");
#endif

                return 1;
        }

#if (NOISY_TEST == 1)
        printf("FAILED!\n");
#endif

        return 0;
}

int main() {

        int newCards, newActions;
        int played = 1;
        int shuffled = 0;
        int seed = 1000;
        int numPlayers = 4;
        int currentPlayer = 0;
        int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int failed = 0;

        int i = 0;
        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                        sea_hag, tribute, smithy, council_room};
        struct gameState G, testG;

        printf("\n*--------------- TESTING CARDTEST3 - VILLAGE ---------------*\n\n");

        initializeGame(numPlayers, k, seed, &G);        //initialize new game

        memcpy(&testG, &G, sizeof(struct gameState));   //copy into testG

        //villageEffect(currentPlayer, &testG, handPos);
	cardEffect(village, choice1, choice2, choice3, &testG, handPos, &bonus);

        newCards = 1;
	newActions = 2;

#if (NOISY_TEST == 1)
        printf("--Hand count = %d, expected = %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer] + newCards - played);
#endif

        if (assertTrue(testG.handCount[currentPlayer], G.handCount[currentPlayer] + newCards - played) == 0) {

                failed++;
        }

#if (NOISY_TEST == 1)
	printf("--Actions = %d, expected %d\n", testG.numActions, G.numActions + newActions);
#endif

	if (assertTrue(testG.numActions, G.numActions + newActions) == 0) {

		failed++;
	}

#if (NOISY_TEST == 1)
        printf("--Deck count = %d, expected = %d\n", testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - newCards + shuffled);
#endif

        if (assertTrue(testG.deckCount[currentPlayer], G.deckCount[currentPlayer] - newCards + shuffled) == 0) {

                failed++;
        }

#if (NOISY_TEST == 1)
        printf("--Played count = %d, expected %d\n", testG.playedCardCount, played);
#endif

        if (assertTrue(testG.playedCardCount, played) == 0) {

                failed++;
        }

#if (NOISY_TEST == 1)
        printf("--Checking other players' hands, no change should occur\n");
#endif

        for (i = 1; i < numPlayers; ++i) {      //player 0 is current, check others

#if (NOISY_TEST == 1)
		printf("--Checking player %d\n", i + 1);
#endif

                if (assertTrue(testG.handCount[i], G.handCount[i]) == 0) {

                        failed++;
                }

                if (assertTrue(testG.deckCount[i], G.deckCount[i]) == 0) {

                        failed++;
                }

                if (assertTrue(testG.discardCount[i], G.discardCount[i]) == 0) {

                        failed++;
                }
        }

#if (NOISY_TEST == 1)
        printf("--Check supply piles, no piles should change\n");
#endif

        for (i = 0; i < 27; ++i) {

#if (NOISY_TEST == 1)
                printf("--Checking card %d..\n", i);
#endif

                if (assertTrue(testG.supplyCount[i], G.supplyCount[i]) == 0) {

                        failed++;
                }
        }

        if (failed > 0) {

                printf("\n*--------------- %d TESTS FAILED! ---------------*\n\n", failed);
        }
        else {

                printf("\n*--------------- ALL TESTS PASSED! ---------------*\n\n");
        }

	return 0;
}

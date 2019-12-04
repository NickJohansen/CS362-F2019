#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Bug: first if both nextplayer become currentplayer

int main(int argc, char **argv)
{

	int seed = 1000;

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState G;

	printf("Unit Test 8\n");

	memset(&G, 23, sizeof(struct gameState)); // set the game state
	initializeGame(2, k, seed, &G);			  // initialize a new game
	G.numPlayers = 2;
	G.whoseTurn = 0;
	G.numActions = 1;
	G.numBuys = 1;
	G.coins = 10;
	G.hand[0][0] = ambassador;
	G.hand[0][1] = ambassador;
	G.hand[0][2] = ambassador;
	G.deckCount[0] = 0;
	G.deckCount[1] = 1;
	G.deck[1][0] = gold;
	G.discardCount[0] = 0;
	G.discardCount[1] = 1;
	G.handCount[0] = 3; // set any other variables
	int c3 = 0;
	int handpos = 2;
	int result = cardEffect(ambassador, 1, 1, c3, &G, handpos, 0);
	if (result == -1)
	{
		printf("Test ambassador compare Failed [FAIL]\n");
	}
	else if (result == 0)
	{
		printf("Test ambassador compare Passed [PASS]\n");
	}

	return 0;
}
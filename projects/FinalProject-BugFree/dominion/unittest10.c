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

	printf("Unit Test 10\n");

	memset(&G, 23, sizeof(struct gameState)); // set the game state
    initializeGame(2, k, seed, &G);  // initialize a new game
	G.numPlayers = 2;
	G.whoseTurn = 0;
	G.numActions = 1;
	G.numBuys = 1;
	G.coins = 10;
	G.hand[0][0] = curse;
	G.deckCount[0] = 0;
	G.deckCount[1] = 1;
	G.deck[1][0] = curse;
	G.discardCount[0] = 0;
	G.discardCount[1] = 1;
    G.playedCardCount = 0;
	G.handCount[0] = 1; // set any other variables

    G.deck[1][G.deckCount[1] -1] = curse;
    G.deck[1][-2] = curse;

	int c3 = 0;
	int handpos = 1;
    int actBefore =  G.numActions;
    
	cardEffect(tribute, 0, 0, c3, &G, handpos, 0);
    
	if(G.numActions == actBefore){
		printf("Test for tribute revealed cards Passed [PASS]\n");
	}
	else{
		printf("Test for tribute revealed cards Failed [FAIL]\n");
	}

	return 0;
}
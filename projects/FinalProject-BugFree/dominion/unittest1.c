#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//bug: for loop starts at 1 not 0, discards 1st cart not 0th

int main (int argc, char** argv){
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };// declarethe game state
	struct gameState game1;// declarethe arrays 
	int seed = 38;
	int c1;
	int c2;
	int c3 = 0;
	int hand;
	
	printf("Unit Test 1\n");
//
// set the state of your variables
// comment on what this is going totest
//
	memset(&game1, 23, sizeof(struct gameState));   // set the game state 
	int r1 = initializeGame(2, k, seed, &game1); // initialize a new game
	c1 = 5;
	c2 = 2;
	c2 = 0;
	hand = 0;
	game1.numPlayers = 2;
	game1.whoseTurn = 0;
	game1.numActions = 1;
	game1.numBuys = 1;
	game1.coins = 10;
	game1.hand[0][0] = gold;
	game1.hand[0][6] = gold;
	game1.hand[0][12] = copper;
	game1.discardCount[0] = 0;
	game1.playedCardCount = 0;
	game1.handCount[0] = 2; // set any other variables
	cardEffect(mine, c1, c2, c3, &game1, hand, 0);
	if(game1.playedCardCount == 1){
		printf("Test for discard card trashing [FAIL]\n");
	}
	else{
		printf("Test for discard card trashing [PASS]\n");
	}

}
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
	struct gameState game2;
	int seed = 38;
	int c1;
	int c2;
	int c3;
	int hand;
	int* bonasu = 0;
	
	printf("Begin Testing do_mine():\n");
//
// set the state of your variables
// comment on what this is going totest
//
	memset(&game1, 23, sizeof(struct gameState));   // set the game state 
	int r1 = initializeGame(2, k, seed, &game1); // initialize a new game
	c1 = 1;
	c2 = 0;
	c2 = 0;
	hand = 0;
	game1.numPlayers = 2;
	game1.whoseTurn = 0;
	game1.numActions = 1;
	game1.numBuys = 1;
	game1.coins = 10;
	game1.hand[0][0] = silver;
	game1.handCount[0] = 1; // set any other variables
	//cardEffect(estate, c1, c2, c3, game1, hand,bonasu);
	if(cardEffect(mine, c1, c2, c3, &game1, hand,bonasu) == -1){
		printf("Test for wrong card Passed [PASS]\n");
	}
	else{
		printf("Test for wrong card Failed [FAIL]\n");
	}

	// verify that your assertspass, for the bugs your asserts may fail
	
	//
	// adjustthe state of your variables to continue testing the function
	// comment on what this is going to test
	//
	memset(&game2, 23, sizeof(struct gameState));   // set the game state 
	int r2 = initializeGame(2, k, seed, &game2); // initialize a new game
	c1 = baron;
	c2 = baron;
	c2 = 0;
	hand = 0;
	game2.numPlayers = 2;
	game2.whoseTurn = 0;
	game2.numActions = 1;
	game2.numBuys = 1;
	game2.coins = 10;
	game2.hand[0][0] = mine;
	game2.hand[0][1] = adventurer;
	game2.handCount[0] = 2; // set any other variables
	cardEffect(mine, c1, c2, c3, &game2, hand,bonasu);
	if(game2.handCount[0] == 1){
		printf("Test for discarding 1 card Passed [PASS]\n");
	}
	else{
		printf("Test for discarding 1 card Failed [FAIL]\n");
	}
	
	if(game2.hand[0][2] == baron){
		printf("Test for discarding and gaining card Passed [PASS]\n");
	}
	else{
		printf("Test for discarding and gaining card Failed [FAIL]\n");
	}
	
	printf("Testcompleted!\n");
}
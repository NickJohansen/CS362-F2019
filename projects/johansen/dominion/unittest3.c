#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//bug: iterator starts at 1 not 0

int main (int argc, char** argv){
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };// declarethe game state
	struct gameState game1;// declarethe arrays 
	struct gameState game2;
	struct gameState game3;
	int seed = 38;
	int c1;
	int c2;
	int c3;
	int hand;
	int* bonasu = 0;
	
	printf("Begin Testing do_baron():\n");
//
// set the state of your variables
// comment on what this is going totest
//
	memset(&game1, 23, sizeof(struct gameState));   // set the game state 
	int r1 = initializeGame(2, k, seed, &game1); // initialize a new game
	c1 = -1;
	c2 = 0;
	c2 = 0;
	hand = 0;
	game1.numPlayers = 2;
	game1.whoseTurn = 0;
	game1.numActions = 1;
	game1.numBuys = 1;
	game1.coins = 10;
	game1.hand[0][0] = baron;
	game1.supplyCount[0] = 5;
	game1.handCount[0] = 1; // set any other variables
	cardEffect(baron, c1, c2, c3, &game1, hand, bonasu);
	if(game1.handCount[0] == 2){
		printf("Test for gaining a card Passed [PASS]\n");
	}
	else{
		printf("Test for gaining a card Failed [FAIL]\n");
	}
// verify that your assertspass, for the bugs your asserts may fail
	
	//
	// adjustthe state of your variables to continue testing the function
	// comment on what this is going to test
	//
	memset(&game2, 23, sizeof(struct gameState));   // set the game state 
	int r2 = initializeGame(2, k, seed, &game2); // initialize a new game
	c1 = 1;
	c2 = 0;
	c2 = 0;
	hand = 0;
	game2.numPlayers = 2;
	game2.whoseTurn = 0;
	game2.numActions = 1;
	game2.numBuys = 1;
	game2.coins = 10;
	game2.hand[0][0] = baron;
	game2.hand[0][1] = estate;
	game2.handCount[0] = 1; // set any other variables
	game2.handCount[1] = 6;
	cardEffect(baron, c1, c2, c3, &game2, hand,bonasu);
	if(game2.coins == 14){
		printf("Test for getting 4 coins Passed [PASS]\n");
	}
	else{
		printf("Test for getting 4 coins Failed [FAIL]\n");
	}
	if(game2.handCount[1] == 0){
		printf("Test for estate card found Passed [PASS]\n");
	}
	else{
		printf("Test for estate card found Failed [FAIL]\n");
	}
	
	memset(&game3, 23, sizeof(struct gameState));   // set the game state 
	int r3 = initializeGame(2, k, seed, &game3); // initialize a new game
	c1 = 1;
	c2 = 0;
	c2 = 0;
	hand = 0;
	game3.numPlayers = 2;
	game3.whoseTurn = 0;
	game3.numActions = 1;
	game3.numBuys = 1;
	game3.coins = 10;
	game3.hand[0][0] = estate;
	game3.hand[0][1] = baron;
	game3.handCount[0] = 1; // set any other variables
	game3.handCount[1] = 6;
	game1.supplyCount[0] = 5;
	cardEffect(baron, c1, c2, c3, &game3, hand,bonasu);
	if(game3.hand[0][0] == estate){
		printf("Test for discarding estate Failed [FAIL]\n");
	}
	else{
		printf("Test for discarding estate Passed [PASS]\n");
	}
	
	if(game1.supplyCount[0] == 4){
		printf("Test for supply decrement Passed [PASS]\n");
	}
	else{
		printf("Test for supply decrement Failed [FAIL]\n");
	}
	
	printf("Testcompleted!\n");
}
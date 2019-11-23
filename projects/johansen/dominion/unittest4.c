#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Bug: first if both nextplayer become currentplayer

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
	
	printf("Begin Testing do_tribute():\n");
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
	game1.hand[0][0] = tribute;
	game1.deckCount[0] = 0;
	game1.deckCount[1] = 1;
	game1.deck[1][0] = gold;
	game1.discardCount[0] = 0;
	game1.discardCount[1] = 1;
	game1.handCount[0] = 1; // set any other variables
	cardEffect(tribute, c1, c2, c3, &game1, hand, bonasu);
	if(game1.deckCount[1] == 0){
		printf("Test for decrementing deck count for next player Passed [PASS]\n");
	}
	else{
		printf("Test for decrementing deck count for next player Failed [FAIL]\n");
	}
	if(game1.discardCount[1] == 0){
		printf("Test for decrementing discard count for next player Passed [PASS]\n");
	}
	else{
		printf("Test for decrementing discard count for next player Failed [FAIL]\n");
	}
	if(game1.coins == 12){
		printf("Test for adding coins Passed [PASS]\n");
	}
	else{
		printf("Test for adding coins Failed [FAIL]\n");
	}

// verify that your assertspass, for the bugs your asserts may fail
	
	//
	// adjustthe state of your variables to continue testing the function
	// comment on what this is going to test
	//
	memset(&game2, 23, sizeof(struct gameState));   // set the game state 
	int r2 = initializeGame(2, k, seed, &game2); // initialize a new game
	c1 = 0;
	c2 = 1;
	c2 = 0;
	hand = 0;
	game2.numPlayers = 2;
	game2.whoseTurn = 0;
	game2.numActions = 1;
	game2.numBuys = 1;
	game2.coins = 10;
	game2.hand[0][0] = tribute;
	game2.deckCount[0] = 2;
	game2.deck[0][0] = estate;
	game2.deck[0][1] = estate;
	game2.deckCount[1] = 0;
	game2.deck[1][0] = estate;
	game2.discardCount[0] = 0;
	game2.discardCount[1] = 1;
	game2.discard[1][0] = estate;
	game2.handCount[0] = 1;
	cardEffect(tribute, c1, c2, c3, &game2, hand,bonasu);
	if(game2.discardCount[1] == 0){
		printf("Test for discard count check Passed [PASS]\n");
	}
	else{
		printf("Test for discard count check Failed [FAIL]\n");
	}
	
	if(game2.deckCount[1] == 0){
		printf("Test for deck count check Passed [PASS]\n");
	}
	else{
		printf("Test for deck count check Passed [FAIL]\n");
	}
	
	printf("Testcompleted!\n");
}
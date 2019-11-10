#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

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
	
	printf("Begin Testing do_ambassador():\n");

////////////////////////////////////////////////////////////////////////

	memset(&game1, 23, sizeof(struct gameState));   // set the game state 
	int r1 = initializeGame(2, k, seed, &game1); // initialize a new game
	c1 = 0;
	c2 = 2;
	c2 = 0;
	hand = 1;
	game1.numPlayers = 2;
	game1.whoseTurn = 0;
	game1.numActions = 1;
	game1.numBuys = 1;
	game1.coins = 10;
	game1.hand[0][0] = minion;
	game1.handCount[0] = 1; // set any other variables
	if(cardEffect(ambassador, c1, c2, c3, &game1, hand,bonasu) == -1){
		printf("Test for failing choice [PASS]\n");
	}
	else{
		printf("Test for failing choice Failed [FAIL]\n");
	}

//////////////////////////////////////////////////////////////////////
	memset(&game2, 23, sizeof(struct gameState));   // set the game state 
	int r2 = initializeGame(2, k, seed, &game2); // initialize a new game
	c1 = 1;
	c2 = 1;
	c2 = 0;
	hand = 0;
	game2.numPlayers = 2;
	game2.whoseTurn = 0;
	game2.numActions = 1;
	game2.numBuys = 1;
	game2.coins = 10;
	game2.hand[0][0] = ambassador;
	game2.handCount[0] = 1; // set any other variables
	game2.handCount[1] = 0;
	if(cardEffect(ambassador, c1, c2, c3, &game2, hand,bonasu) == -1){
		printf("Test for not having enough cards Passed [PASS]\n");
	}
	else{
		printf("Test for not having enough cards Failed [FAIL]\n");
	}

///////////////////////////////////////////////////////////////////////
	memset(&game3, 23, sizeof(struct gameState));   // set the game state 
	int r3 = initializeGame(2, k, seed, &game3); // initialize a new game
	c1 = 1;
	c2 = 1;
	c2 = 0;
	hand = 0;
	game3.numPlayers = 2;
	game3.whoseTurn = 0;
	game3.numActions = 1;
	game3.numBuys = 1;
	game3.coins = 10;
	game3.hand[0][0] = ambassador;
	game3.hand[0][1] = baron;
	game3.hand[0][2] = baron;
	game3.handCount[0] = 3; // set any other variables
	game3.handCount[1] = 0;
	game1.supplyCount[0] = 5;
	cardEffect(ambassador, c1, c2, c3, &game3, hand,bonasu);
	if(game3.handCount[1] == 1){
		printf("Test for other players gaining card Passed [PASS]\n");
	}
	else{
		printf("Test for other players gaining card Failed [FAIL]\n");
	}
	
	if(game3.handCount[0] == 0){
		printf("Test for getting rid of current player's cards Passed [PASS]\n");
	}
	else{
		printf("Test for getting rid of current player's cards Failed [FAIL]\n");
	}
	
	printf("Testcompleted!\n");
}
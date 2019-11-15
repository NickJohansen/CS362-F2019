#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) {
	//tribute
	srand(time(NULL));
	struct gameState game1;// declarethe arrays 
	struct gameState game2;
	int c1;
	int c2;
	int c3;
	int turns = 0;
	int handpos = 0;
	int* bonasu = 0;
	game1.numPlayers = MAX_PLAYERS;
	game1.playedCardCount = 0;
	int go = 1;

	while (go) {
		int hand = 0;
		c1 = rand() % 2;
		c2 = rand() % 2;
		game1.whoseTurn = rand() % 2;
		game2.whoseTurn = game1.whoseTurn;
		game1.numActions = 1;
		game2.numActions = 1;
		game1.numBuys = rand() % 2;
		game2.numBuys = game1.numBuys;
		game1.coins = 10;
		game1.deckCount[0] = rand() % 5;
		game2.deckCount[0] = game1.deckCount[0];
		game1.deckCount[1] = rand() % 5;
		game2.deckCount[1] = game1.deckCount[1];
		game1.handCount[0] = 0;
		game2.handCount[0] = 0;

		for (int i = 0; i < game1.deckCount[0]; i++) {
			game1.hand[0][i] = rand() % 20;
			game2.hand[0][i] = game1.hand[0][i];
			game1.handCount[0]++;
			game2.handCount[0]++;
		}

		for (int i = 0; i < game1.deckCount[1]; i++) {
			game1.hand[1][i] = rand() % 20;
			game2.hand[1][i] = game1.hand[1][i];
			game1.handCount[1]++;
			game2.handCount[1]++;
		}
		game1.discardCount[0] = rand() % 2;
		game2.discardCount[0] = game1.discardCount[0];
		game1.discardCount[1] = rand() % 2;
		game2.discardCount[1] = game1.discardCount[1];


		game1.handCount[0] = 1; // set any other variables
		cardEffect(tribute, c1, c2, c3, &game1, hand, bonasu);
		
		if (game2.discardCount[game2.whoseTurn] + game2.deckCount[game2.whoseTurn] < 1) {
			if (game2.discardCount[game2.whoseTurn] > 0) {
				if (game2.discardCount[game2.whoseTurn] == game1.discardCount[game1.whoseTurn] + 1)
					printf("Tribute Successfully Discarded card [PASS]\n");
				else
					printf("Tribute Unsuccessfully Discarded card [FAIL]\n");
			}
			else {
				if (game2.deckCount[game2.whoseTurn] == game1.deckCount[game1.whoseTurn] + 1)
					printf("Tribute Successfully decremented deck [PASS]\n");
				else
					printf("Tribute Unsuccessfully decremented deck [FAIL]\n");
			}
		}
		else {
			if (game2.deckCount[game2.whoseTurn] == game1.deckCount[game1.whoseTurn] + 2)
				printf("Tribute Successfully got rid of deck [PASS]\n");
			else
				printf("Tribute Unsuccessfully got rid of deck [FAIL]\n");
		}
		if ((game2.deckCount[game2.whoseTurn] + 2 == game1.deckCount[game1.whoseTurn]) || game1.numActions == 3 || game1.coins == 12)
			printf("Tribute Successfully went through for loop [PASS]\n");
		else
			printf("Tribute Unsuccessfully went through for loop [PASS]\n");
		turns++;
		if (turns == 500) {
			go = 0;
		}
	}

}
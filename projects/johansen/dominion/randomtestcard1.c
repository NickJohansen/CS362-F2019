#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) {
	//baron
	srand(time(NULL));
	struct gameState game1;// declarethe arrays
	int c1;
	int c2;
	int c3;
	int turns = 0;
	int hand = 0;
	int* bonasu = 0;
	int count;

	game1.numPlayers = MAX_PLAYERS;
	game1.playedCardCount = 0;
	int go = 1;
	while (go == 1) {
		c1 = rand() % 2;
		c2 = rand() % 2;
		c2 = 0;
		hand = 0;
		game1.whoseTurn = 0;
		game1.numActions = rand() % 5;
		game1.numBuys = 1;
		game1.coins = 10;
		game1.hand[0][0] = rand() % 20;
		game1.hand[0][1] = rand() % 20;
		game1.supplyCount[0] = rand() % 20;
		count = rand() % 10;
		game1.handCount[0] = count; // set any other variables
		cardEffect(baron, c1, c2, c3, &game1, hand, bonasu);
		if (c1 == 0) {
			if (game1.hand[0][1] == estate) {
				if (game1.coins == 14)
					printf("Baron successfully added coins [PASS]\n");
				else
					printf("Baron unsuccessfully added coins [PASS]\n");
			}
			else {
				if (game1.handCount[0] == (count + 1))
					printf("Baron succesfully gained a card [PASS]\n");
				else
					printf("Baron unsuccesfully gained a card [FAIL]\n");
			}
		}
		else {
			if (game1.supplyCount[0] > 0) {
				if (game1.handCount[0] == (count + 1))
					printf("Baron succesfully gained a card [PASS]\n");
				else
					printf("Baron unsuccesfully gained a card [FAIL]\n");
			}
		}
		turns++;
		if (turns == 500)
			go = 0;
	}
}
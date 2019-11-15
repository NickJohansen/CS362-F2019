#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) {
	//minion
	srand(time(NULL));
	struct gameState game1;// declarethe arrays 
	int c1;
	int c2;
	int c3;
	int turns = 0;
	int player_1;
	int player_2;
	int handpos = 0;
	int* bonasu = 0;
	game1.numPlayers = MAX_PLAYERS;
	game1.playedCardCount = 0;

	int i, j, k, l, cop, sil, gol;
	int go = 1;

	while (go == 1) {
		player_1 = 0;
		player_2 = 0;
		c1 = rand() % 2;
		c2 = rand() % 2;
		cop = rand() % 20;
		sil = rand() % 20;
		gol = rand() % 20;
		game1.coins = 0;
		game1.whoseTurn = rand() % 2;
		i = 0;
		printf("\n ----------Beginning Minion Test----------\n");
		while (i < 2) {
			j = 0;
			k = 0;
			l = 0;

			while (j < cop) {
				game1.deck[i][j] = copper;
				j++;
			}
			game1.deckCount[i] = j + 1;
			while (k < sil) {
				game1.hand[i][k] = silver;
				k++;
			}
			game1.handCount[i] = k + 1;
			game1.handCount[i + 2] = k + 1;
			while (l < gol) {
				game1.discard[i][l] = gold;
				l++;
			}
			game1.discardCount[i] = l + 1;
			i++;
		}
		printf("Turns Passed: &d  Whose Turn: %d\n Choice1: %d, Choice2: %d\n", turns, game1.whoseTurn,c1,c2);
		k = cardEffect(minion, c1, c2, c3, &game1, handpos, bonasu);
		printf("Coins in game: %d\n", game1.coins);
		i = 0;
		while (i < game1.handCount[0]) {
			if (game1.hand[0][i] != silver) {
				player_1 = 1;
			}
			i++;
		}
		i = 0;
		while (i < game1.handCount[1]) {
			if (game1.hand[1][i] != silver) {
				player_2 = 1;
			}
			i++;
		}
		if (c1 == 1) {
			if (player_1 == 1)
				printf("Minion edited players hand [FAIL]\n");
			else
				printf("Minion did not edit players hand [PASS]\n");

			if (player_2 == 1)
				printf("Minion edited players hand [FAIL]\n");
			else
				printf("Minion did not edit players hand [PASS]\n");

			if (game1.coins != 2)
				printf("Minion gives back incorrect coins [FAIL]\n");
			else
				printf("Minion gives back correct coins [PASS]\n");
			
			go = 0;
		}
		if (c2 == 1) {
			if (player_1 == 1)
				printf("Minion edited players hand [PASS]\n");
			else
				printf("Minion did not edit players hand [FAIL]\n");
			if (player_2 == 1){
				if (game1.handCount[3] > 4)
					printf("Minion edited cards in hand when more than 4 [PASS]\n");
				else
					printf("Minion edited cards in hand when less than 4 [FAIL]\n");
			}
			else {
				if (game1.handCount[3] > 4)
					printf("Minion did not edit cards in hand when more than 4 [FAIL]\n");
				else
					printf("Minion edited cards in hand when more than 4 [PASS]\n");
			}
			go = 0;
		}
		else {
			if (player_1 == 1)
				printf("Minion edited cards in players hand[FAIL]\n");
			else
				printf("Minion did not edit cards in players hand[PASS]\n");

			if (player_2 == 1)
				printf("Minion edited cards in players hand[FAIL]\n");
			else
				printf("Minion did not edit cards in players hand[PASS]\n");

			if (game1.coins != 0)
				printf("Minion gives incorrect coins [FAIL]\n");
			else
				printf("Minion gives correct coins [PASS]\n");
			go = 0;
		}
		turns++;
	}
	return 0;
}
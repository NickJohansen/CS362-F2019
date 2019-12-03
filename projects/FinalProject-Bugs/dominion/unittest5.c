#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (){
  int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };// declarethe game state
  struct gameState game1, game2; // declarethe arrays
  int seed = 38;
  int c1;
  int c2;
  int c3;
  int hand;

  printf("Unit Test 5\n");
  int r1 = initializeGame(2, k, seed, &game1);
  memcpy(&game2, &game1, sizeof(struct gameState));
  int currentPlayer = whoseTurn(&game1);
  if(game1.discardCount[currentPlayer] = game2.deckCount[currentPlayer]){
      printf("Test for cheking scoreFor Failed [FAIL]\n");
  }
  else{
      printf("Test for cheking scoreFor Passed [FAIL]\n");
  }
  return 0;
}

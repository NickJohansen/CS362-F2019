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

  printf("Unit Test 6\n");

  //initialize gameState
  int r1 = initializeGame(2, k, seed, &game1);
  memcpy(&game2, &game1, sizeof(struct gameState));
  //copy current gameState

  //call Feast
  cardEffect(feast, c1, c2, c3, &game1, hand, 0);


  printf("Feast does not increase coins directly: ");
  if(game1.coins == game2.coins){
      printf("Test for increase coins Passed [PASS]\n");
  }else{
      printf("Test for increase coins Failed [FAIL]\n");
  }

  return 0;
}

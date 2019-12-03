#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };// declarethe game state
    int seed = 38;
    int c1;
    int c2;
    int c3;
    int hand;
    int bonus = 0;
    struct gameState game1, game2;
    printf("Unit Test 7\n");
    initializeGame(2, k, seed, &game1);
    memcpy(&game2, &game1, sizeof(struct gameState));
    cardEffect(tribute, c1, c2, c3, &game2, hand, bonus);
    if(game2.numActions > game1.numActions + 4){
        printf("Test for adding actions is Failed [FAIL]\n");
    }
    if(game2.coins > game1.coins + 4){
        printf("Test for adding coins is Failed [FAIL]\n");
    }
    if(numHandCards(&game1) <= numHandCards(&game2) + 2){
        printf("Test for adding cards is Failed [FAIL]\n");
    }
    else{
        printf("Test for loop Passed [PASS]\n");
    }
    return 0;
}

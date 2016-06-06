#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

//Village test

int main(int argc, char** argv){
	
	int numTests = atoi(argv[1]);
	srand(time(NULL));
	int passed = 0;
	
	for(int i = 0; i < numTests; i++){
		int good = 0;
		int numPlayers = rand() %(MAX_PLAYERS - 1) + 2;
		
		struct gameState game;
		int k[10] = {adventurer, gardens, embargo, village, steward, mine, cutpurse, sea_hag, tribute, smithy};
		
		initializeGame(numPlayers, k, rand(), &game);
		
		int player = rand() % numPlayers;
		game.whoseTurn = player;
		int bonus = rand() % 50;
        int choice1 = rand() % 50;
        int choice2 = rand() % 50;
        int choice3 = rand() % 50;
        int handPos = rand() % MAX_HAND;

        struct gameState orig;
        memcpy(&orig, &game, sizeof(struct gameState));
		
		cardEffect(village, choice1, choice2, choice3, &game, handPos, &bonus);
		
		if(game.numActions > orig.numActions){
			good++;
		}else if(game.numActions < orig.numActions){
			printf("Actions error\n");
		}
		if(game.handCount[player] == orig.handCount[player]){
			good++;
		}else if(game.handCount[player] != orig.handCount[player]){
			printf("Draw error\n");
			printf("Cards in Hand: %d ", game.handCount[player]);
			printf("Should be: %d ", orig.handCount[player]);
		}
		if(good >= 2){
			passed++;
		}
		
	}
	printf("RandomTestVillage: %d of %d TESTS PASSED\n", passed, numTests);
}


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

//Adventurer test

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
		
		cardEffect(adventurer, choice1, choice2, choice3, &game, handPos, &bonus);
		
		if(game.handCount[player] == orig.handCount[player] + 2){
			good++;
		}
		int cardDrawn1 = game.hand[player][game.handCount[player] - 1];
		if(cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold){
            good++;
        }
		int cardDrawn2 = game.hand[player][game.handCount[player] - 2];
        if(cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold){         
            good++;
        }
		if(good >= 3){
			passed++;
		}
		
		
	}
	printf("RandomTestAdventurer: %d of %d TESTS PASSED\n", passed, numTests);
}
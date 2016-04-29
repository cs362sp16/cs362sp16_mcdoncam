#include <assert.h>
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <time.h>
  
  //Tests for discardCard()
  int main(int arc, char **argv){
	  
	  printf("discardCard Test \n");
	  
	  srand(time(NULL));
	  
	  int numplayers = rand() % (MAX_PLAYERS -1) +1;
	  struct gameState G;
	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	  initializeGame(numplayers, k, rand(), &G);
	  printf("Random Tests\n");
	  
	  int numtests = 100; 
	  for(int i = 0; i < numtests; i++){
		  struct gameState orig;
		  memcpy(&orig, &G, sizeof(struct gameState));
		  
		  int trash = rand() % 2;
		  int player = rand() % numplayers;
		  if(G.handCount[player] > 0){
			  discardCard(G.handCount[player] - 1, player, &G, trash);
			  assert(orig.handCount[player] - 1 == G.handCount[player]);
			  if(!trash) assert(orig.playedCardCount + 1 == G.playedCardCount);
			  
		  }
		  
	  }
		printf("discardCard Test OK\n");
	  
  }
#include <assert.h>
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <time.h>
  //Tests for drawCard()
  int main(int arc, char **argv){
	  
	  printf("drawCard Test \n");
	  
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
		  
		 
		  //int player = rand() % numplayers;
		  if(G.handCount[1] > 0){
			  drawCard(G.whoseTurn, &G);
			  assert(orig.handCount[1] + 1 == G.handCount[1]);
			  assert(orig.deckCount[1] - 1 == G.deckCount[1]);
			  
		  }
		  
	  }
				printf("drawCard Test OK\n");
	  
  }
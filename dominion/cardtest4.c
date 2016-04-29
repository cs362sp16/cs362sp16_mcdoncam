#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include "dominion.c"

int main (int argc, char** argv) {
  struct gameState G;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

  printf ("Starting game.\n");


  srand(time(NULL));
  int rando = ( rand()%10 );
  int r = initializeGame(2, k, rando, &G);
  assert (r == 0);


  gainCard(gardens, &G, 1, 1);                       
  int deckCount = fullDeckCount(1, 0, &G);           
  int cE = cardEffect(gardens, 0, 0, 0, &G, 0, 0);
  assert (cE == -1);                              

  int getp1Score = scoreFor(1, &G);
  getp1Score = getp1Score - 3;                    
  assert (getp1Score == (deckCount / 10));


  assert (getp1Score == 1);

  return 0;
}
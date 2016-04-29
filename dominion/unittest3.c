#include <assert.h>
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <time.h>
//Tests for kingdomCards()
int main(int arc, char **argv){
	  
	printf("kingdomCard Test \n");
	  
	srand(time(NULL));
	  	  
	int numtests = 1000; 
	  
	for(int i = 0; i < numtests; i++){
		int j[10] = { rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand() };
		int *k = kingdomCards( j[0], j[1], j[2], j[3], j[4], j[5], j[6], j[7], j[8], j[9]); 
			for(int z = 0; z < 10; z++){
				assert(j[z] == k[z]);
			}
	}
		
	  		printf("kingdomCard Test OK\n");
}
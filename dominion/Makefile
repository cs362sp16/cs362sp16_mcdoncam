CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c -std=c99 dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittestresults.out: unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o cardtest2.o cardtest3.o 
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	cat unittest1.c.gcov >> unittestresults.out	
	gcov unittest2.c >> unittestresults.out
	cat unittest2.c.gcov >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	cat unittest3.c.gcov >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	cat unittest4.c.gcov >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	cat cardtest1.c.gcov >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	cat cardtest2.c.gcov >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	cat cardtest3.c.gcov >> unittestresults.out

	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
tests: unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o cardtest2.o cardtest3.o  

unittest1.o: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  -std=c99 unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2.o: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  -std=c99 unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3.o: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  -std=c99 unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4.o: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  -std=c99 unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1.o: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  -std=c99 cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2.o: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g  -std=c99 cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3.o: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  -std=c99 cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4.o: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  -std=c99 cardtest4.c dominion.o rngs.o $(CFLAGS)	
	
randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g  -std=c99 randomtestcard1.c dominion.o rngs.o $(CFLAGS)	
	
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g  -std=c99 randomtestcard2.c dominion.o rngs.o $(CFLAGS)	
	
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g  -std=c99 randomtestadventurer.c dominion.o rngs.o $(CFLAGS)		
	
randomtests.out: randomtestadventurer randomtestcard1 randomtestcard2
	./randomtestadventurer 42 &> randomtestadventurer.out
	./randomtestcard1 42 &> randomtestcard1.out
	./randomtestcard2 42 &> randomtestcard2.out 
	gcov -f -b -c randomtestadventurer.c >> randomtestadventurer.out
	gcov -f -b -c randomtestcard1.c >> randomtestcard1.out
	gcov -f -b -c randomtestcard2.c >> randomtestcard2.out
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
clearresults: rm -f *.o unittestresults.out *.gcov *.gcda *.gcno *.so *.a *.dSYM

all: playdom player 


clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM

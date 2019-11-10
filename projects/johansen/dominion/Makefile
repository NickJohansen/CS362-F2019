CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	
unittests: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest5 -g unittest5.c dominion.o rngs.o -coverage $(CFLAGS)
	
unittestresults: unittests 
	./unittest1 >> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out	
	./unittest5 >> unittestresult.out	
	
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out

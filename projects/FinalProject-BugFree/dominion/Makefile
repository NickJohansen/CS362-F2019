CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	
unittests: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c unittest6.c unittest7.c unittest8.c unittest9.c unittest10.c dominion.o rngs.o
	gcc -o unittest1.test -g unittest1.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest2.test -g unittest2.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest3.test -g unittest3.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest4.test -g unittest4.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest5.test -g unittest5.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest6.test -g unittest6.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest7.test -g unittest7.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest8.test -g unittest8.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest9.test -g unittest9.c dominion.o rngs.o -coverage $(CFLAGS)
	gcc -o unittest10.test -g unittest10.c dominion.o rngs.o -coverage $(CFLAGS)
	
unittestresults: unittests 
	./unittest1.test &> unittestresult.out
	./unittest2.test >> unittestresult.out
	./unittest3.test >> unittestresult.out
	./unittest4.test >> unittestresult.out	
	./unittest5.test >> unittestresult.out	
	# ./unittest6.test >> unittestresult.out
	./unittest7.test >> unittestresult.out
	./unittest8.test >> unittestresult.out
	./unittest9.test >> unittestresult.out	
	./unittest10.test >> unittestresult.out	
	
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtests: dominion.o rngs.o randomtestcard1.c randomtestcard2.c randomtestcard3.c
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard3 -g  randomtestcard3.c dominion.o rngs.o $(CFLAGS)

randomtestresults: dominion.o randomtests
	./randomtestcard1 &> randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	./randomtestcard3 >> randomtestresults.out
	
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out *.test

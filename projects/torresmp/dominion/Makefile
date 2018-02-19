CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

unittest1: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: dominion.o cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: dominion.o cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard badTestDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	rm -rf *.dSYM

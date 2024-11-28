CC=gcc
OPTIONS=-W -Wall -std=c89 -pedantic -O2

generation: generation.o 
	$(CC) $(OPTIONS) $^ -o $@

generation.o: generation.c
	$(CC) $(OPTIONS) -c $^

clean :
	rm -rf *.o *~ generation
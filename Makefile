CC=gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3 `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` -lm
O=`pkg-config --libs-only-l MLV`

KNN: main.o conversion.o fonction.o sansdecision.o menu.o arbre.o zone.o heads/type.h
	$(CC) $(OPTIONS) $^ $(O) -o KNN

main.o: sources/main.c heads/type.h
	$(CC) $(OPTIONS) -c sources/main.c

conversion.o: sources/conversion.c heads/conversion.h
	$(CC) $(OPTIONS) -c sources/conversion.c

generation: sources/generation.o
	$(CC) $(OPTIONS) -o generation

generation.o: sources/generation.c heads/generation.h
	$(CC) $(OPTIONS) -c sources/generation.c

fonction.o: sources/fonction.c heads/fonction.h heads/type.h
	$(CC) $(OPTIONS) $(O) -c sources/fonction.c

sansdecision.o: sources/sansdecision.c heads/sansdecision.h heads/type.h
	$(CC) $(OPTIONS) $(O) -c sources/sansdecision.c

menu.o: sources/menu.c heads/menu.h heads/type.h
	$(CC) $(OPTIONS) $(O) -c sources/menu.c

arbre.o: sources/arbre.c heads/arbre.h heads/type.h heads/zone.h
	$(CC) $(OPTIONS) $(O) -c sources/arbre.c

zone.o: sources/zone.c heads/zone.h heads/type.h heads/arbre.h
	$(CC) $(OPTIONS) $(O) -c sources/zone.c

clean :
	rm -rf *.o *~ KNN

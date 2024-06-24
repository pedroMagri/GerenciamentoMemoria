CC = gcc
CFLAGS = -Wall -Wextra -std=c99

OBJ = main.o processo.o quadro.o memoria.o

EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

main.o: main.c processo.h memoria.h
	$(CC) $(CFLAGS) -c main.c

processo.o: processo.c processo.h pagina.h quadro.h
	$(CC) $(CFLAGS) -c processo.c

quadro.o: quadro.c quadro.h
	$(CC) $(CFLAGS) -c quadro.c

memoria.o: memoria.c memoria.h quadro.h processo.h
	$(CC) $(CFLAGS) -c memoria.c

clean:
	rm -f $(EXEC) $(OBJ)

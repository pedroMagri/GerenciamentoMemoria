CC = gcc
CFLAGS = -Wall -Wextra -std=c99

OBJ = main.o processo.o quadro.o memoria.o

EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

main.o: src/main.c includes/processo.h includes/memoria.h
	$(CC) $(CFLAGS) -c src/main.c

processo.o: src/processo.c includes/processo.h includes/pagina.h includes/quadro.h
	$(CC) $(CFLAGS) -c src/processo.c

quadro.o: src/quadro.c includes/quadro.h
	$(CC) $(CFLAGS) -c src/quadro.c

memoria.o: src/memoria.c includes/memoria.h includes/quadro.h includes/processo.h
	$(CC) $(CFLAGS) -c src/memoria.c

clean:
	rm -f $(EXEC) $(OBJ)

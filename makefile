# Compiler und Flags
CC		= gcc
CFLAGS	= -g -Wall
ADDRFLAG= -fsanitize=address

#Zielname
OUTPUT	= OUT

all: main.o TrappedKnight.o Bitarray.o
	gcc TrappedKnight.o Bitarray.o main.o -o $(OUTPUT) $(ADDRFLAG)

main.o: main.c TrappedKnight.h Bitarray.h
	gcc -c main.c -o main.o $(ADDRFLAG)

TrappedKnight.o: TrappedKnight.c TrappedKnight.h Bitarray.h
	gcc -c TrappedKnight.c -o TrappedKnight.o $(ADDRFLAG)

Bitarray.o: Bitarray.c Bitarray.h
	gcc -c Bitarray.c -o Bitarray.o $(ADDRFLAG)

clean:
	rm *.o $(OUTPUT)

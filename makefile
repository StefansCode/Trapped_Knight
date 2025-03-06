# Compiler and Flags
CC		= gcc
CFLAGS	= -g -Wall
ADDRFLAG= -fsanitize=address

#Output names
OUTPUT	= OUT

# link all object files
all: main.o TrappedKnight.o Bitarray.o
	gcc TrappedKnight.o Bitarray.o main.o -o $(OUTPUT) $(ADDRFLAG)


# compile .c-files into object files
main.o: main.c TrappedKnight.h Bitarray.h
	gcc -c main.c -o main.o $(ADDRFLAG)

TrappedKnight.o: TrappedKnight.c TrappedKnight.h Bitarray.h
	gcc -c TrappedKnight.c -o TrappedKnight.o $(ADDRFLAG)

Bitarray.o: Bitarray.c Bitarray.h
	gcc -c Bitarray.c -o Bitarray.o $(ADDRFLAG)


# create libraries
libTrappedKnight.a: TrappedKnight.o
	ar rcs libTrappedKnight.a TrappedKnight.o

libBitarray.a: Bitarray.o
	ar rcs libBitarray.a Bitarray.o


# some othe commands
run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm *.o *.a $(OUTPUT)
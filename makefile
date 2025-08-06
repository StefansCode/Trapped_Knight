# Compiler and Flags
CC		= gcc
CFLAGS	= -g -Wall

#Output names
OUTPUT	= OUT

# link all object files
all: main.o TrappedKnight.o Bitarray.o
	gcc TrappedKnight.o Bitarray.o main.o -o $(OUTPUT)


# compile .c-files into object files
main.o: main.c TrappedKnight.h Bitarray.h
	gcc -c main.c -o main.o

TrappedKnight.o: TrappedKnight.c TrappedKnight.h Bitarray.h
	gcc -c TrappedKnight.c -o TrappedKnight.o

Bitarray.o: Bitarray.c Bitarray.h
	gcc -c Bitarray.c -o Bitarray.o


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

# Windows specific clean command
# /Q 	suppresses error messages if files do not exist
# 2>nul redirects error messages to null device
clean_win:
	del /Q *.o *.a $(OUTPUT) 2>nul
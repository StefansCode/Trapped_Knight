#ifndef BITARRAY_H
#define BITARRAY_H


typedef struct bitarray{
		int x;
		int x_bytes;
		int y;
		unsigned char* start;
}bitarray;


bitarray* init_Bitarray(int x, int y);

int check_Bit(bitarray* Bitarray, int x, int y);

void flip_Bit(bitarray* Bitarray, int x, int y);

void print_Bitarray(bitarray* Bitarray);

void reset_Bitarray(bitarray* Bitarray);


#endif //BITARRAY_H

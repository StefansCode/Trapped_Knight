#ifndef BITARRAY_H
#define BITARRAY_H


typedef struct{
		int x;
		int x_bytes;
		int y;
		unsigned char* start;
}b_arr;


b_arr* init_Bitarray(int x, int y);

int check_Bit(b_arr* Bitarray, int x, int y);

void flip_Bit(b_arr* Bitarray, int x, int y);

void print_Bitarray(b_arr* Bitarray);

void reset_Bitarray(b_arr* Bitarray);


#endif //BITARRAY_H

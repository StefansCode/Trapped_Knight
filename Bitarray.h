#ifndef BITARRAY_H
#define BITARRAY_H


typedef struct bitarray{
		int width;
		int height;
		unsigned char* start;
}bitarray;

bitarray* bitarray_create(int width, int height);

void bitarray_init(bitarray *b, int x, int y);

int bitarray_check_bit(bitarray* Bitarray, int x, int y);

void bitarray_flip_bit(bitarray* Bitarray, int x, int y);

void bitarray_print(bitarray* Bitarray);

void bitarray_reset(bitarray* Bitarray);


#endif //BITARRAY_H

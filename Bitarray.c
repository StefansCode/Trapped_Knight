#include <stdlib.h>
#include <stdio.h>
#include "Bitarray.h"


bitarray* bitarray_init(int x, int y){
	
	if( x%8 != 0 ){
		printf("ERROR: The number of bits in one line of a bitarry must be divisible by 8.\n");
		return NULL;
	}
	
	bitarray* newBitarray = malloc(sizeof(bitarray));
	if(newBitarray == NULL){
		printf("ERROR: Failed to allocate memory for newBitarray.\n");
		return NULL;
	}
	
	newBitarray->width 	 	= x;
	newBitarray->height 	 	= y;
	newBitarray->start 	= malloc((x*y)/8);
	if (newBitarray->start == NULL){
		printf("ERROR: Failed to allocate memory for newBitarray->start.\n");
		return NULL;
	}
	
	bitarray_reset(newBitarray);
	
	return(newBitarray);
}


int bitarray_check_bit(bitarray* Bitarray, int x, int y){
	
	if( x < 0 || x > Bitarray->width || y < 0 || y > Bitarray->height){
		printf("ERROR: Trying to access bit out of bound\n");
		exit(1);
	}
	
	//gehe zum byte welches das gewünschte bit enthält
	unsigned char b = *(Bitarray->start + y*(Bitarray->width)/8 + (x >> 3));
	
	// gib das gewünschte bit aus
	return ( b & ( 1 << (x%8) ) );
}


void bitarray_flip_bit(bitarray* Bitarray, int x, int y){
	
	if( x < 0 || x > Bitarray->width || y < 0 || y > Bitarray->height){
		printf("ERROR: Trying to access bit out of bound\n");
		exit(1);
	}
	
	//gehe zum byte, welches das gewünschte bit enthält
	unsigned char* b = Bitarray->start + y*(Bitarray->width)/8 + (x >> 3);
	
	// flippe das gewünschte bit
	*b = ( *b ^ ( 1 << (x%8) ) );
}


void bitarray_reset(bitarray* Bitarray){
	for(int i=0; i < (Bitarray->width*Bitarray->height)/8; i++){
		*(Bitarray->start + i) = 0;
	}
}


void bitarray_print(bitarray* Bitarray){
	for(int i=0; i < Bitarray->height; i++){
		for(int ii=0; ii < Bitarray->width; ii++){
			if(bitarray_check_bit(Bitarray, ii, i)){
				printf("X ");
			}
			else{
				printf(". ");
				}
		}
		printf("\n");
	}
}
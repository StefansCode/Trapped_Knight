#include <stdlib.h>
#include <stdio.h>
#include "Bitarray.h"
#include "TrappedKnight.h"

int max(int x, int y){
	if(x<y){return y;}
	return x;
}


int Feldwert(int x, int y){
	
	int X = abs(x);
	int Y = abs(y);
	
	if( X <= Y ){
		if( y >= 0 ){
			return (2*Y+1)*(2*Y+1) -   Y + x;
		}
		else{
			return (2*Y+1)*(2*Y+1) - 5*Y - x;
		}
	}
	else{
		if( x <= 0 ){
			return (2*X+1)*(2*X+1) - 3*X + y;
		}
		else{
			return (2*X+1)*(2*X+1) - 7*X - y;
		}
	}
}


int compare_Fieldvalue(const void* a, const void* b){
	int* p1 = (int*) a;
	int* p2 = (int*) b;
	
	return ( Feldwert(p1[0], p1[1]) - Feldwert(p2[0], p2[1]) );
}


void print_spiral(int size){
	
	int x_offset = size/2;
	int y_offset = size/2;
	
	if(!(size%2)){ x_offset--;}

	for(int i=0; i < size; i++){
		for(int ii=0; ii < size; ii++){
			
			printf("%4d",Feldwert(ii-x_offset, y_offset-i));
		
		}
		printf("\n\n");
	}
	
}


int is_prim(int n){
	if(n<2){return 0;}
	for(int i=2; i <= (n/2); i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}


void print_Ulam(int size){
	
	int x_offset = size/2;
	int y_offset = size/2;
	
	if(!(size%2)){ x_offset--;}

	for(int i=0; i < size; i++){
		for(int ii=0; ii < size; ii++){
			
			if(ii-x_offset == 0 && (y_offset-i) == 0){
				printf("X ");
			}
			else if(is_prim(Feldwert(ii-x_offset, y_offset-i))){
				printf("o ");
			}
			else{
				printf("  ");
			}			
		}
		printf("\n");
	}
}


void set_next(int* next, int curr_x, int curr_y, int x_step, int y_step){
	
	// next should point to a 16*sizeof(int) wide space.
	
	next[0 ] =curr_x + x_step; next[1 ] =curr_y + y_step;
	next[2 ] =curr_x + x_step; next[3 ] =curr_y - y_step;
	next[4 ] =curr_x - x_step; next[5 ] =curr_y + y_step;
	next[6 ] =curr_x - x_step; next[7 ] =curr_y - y_step;
	next[8 ] =curr_x + y_step; next[9 ] =curr_y + x_step;
	next[10] =curr_x + y_step; next[11] =curr_y - x_step;
	next[12] =curr_x - y_step; next[13] =curr_y + x_step;
	next[14] =curr_x - y_step; next[15] =curr_y - x_step;
}	


void print_arr(int* arr){
	for(int i=0; i<8; i++){
		printf("[%d,%d], ", arr[2*i],arr[2*i+1]);
	}
	printf("\n");
}


// größe des Bitfelds sollte durch 8 teilbar sein.
int Field_size = 8192;


int* TK(int* output, int x_start, int y_start, int x_movement, int y_movement){
	
	printf("(%4d,%4d) => ", x_movement, y_movement);
	
	// Initialise the bit-field.
	bitarray* Field = bitarray_create(Field_size, Field_size);
	if(Field == NULL){
		return NULL;
	}
	
	// allocate space to hold possible next positions at every step.
	int* next  = malloc(16*sizeof(int));
	if(next == 0){
		printf("ERROR: Failed to allocate memory for next");
		return NULL;
	}
	
	// Start at (0,0)
	int current_x = x_start;
	int current_y = y_start;

	// Maximale Itterations if something goes wrong.
	int maxitt = 1000000000; //1 Milliarden
	int itt = 1;
	while(itt < maxitt){	
		
		// Mark the current position as visited.
		bitarray_flip_bit(Field, current_x + ((Field_size/2)-1), (Field_size/2)-current_y);
		
		
		// Fill next with all possible next positions
		set_next(next, current_x, current_y, x_movement, y_movement);
		
		// Sort them by their fieldvalue.
		qsort(next, 8, 8, compare_Fieldvalue );
		
		// betrachte die möglichen nächsten Positionen und
		// gehe zur kleinsten noch freien Position.
		int i;
		for(i=0; i<8; i++){
			if(!bitarray_check_bit(Field, next[2*i]+((Field_size/2)-1), (Field_size/2)-next[2*i+1])){
				current_x = next[2*i  ];
				current_y = next[2*i+1];
				break;
			}	
		}
	
		// Wenn alle möglichen nächsten Positionen besetzt sind, breche den Loop ab.
		if(i==8){
			break;
		}
		itt++;
	}
	
	
	printf("(%4d,%4d), %7d", current_x, current_y, itt);
	if(itt == maxitt){
		printf("  maxitt!");
	}
	printf("\n");
	
	bitarray_destroy(Field);
	free(Field);
	free(next);
	
	output[0] = current_x;
	output[1] = current_y;
	output[2] = itt;
	
	return output;
}



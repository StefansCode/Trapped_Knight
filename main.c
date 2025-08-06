#include <stdlib.h>
#include <stdio.h>
#include "Bitarray.h"
#include "TrappedKnight.h"

#include <unistd.h>

int main(void){

	int* output = malloc(3 * sizeof(int));
	if(output == NULL){
		return 1;
	}

	for(int i=2; i < 101; i++){
		for(int ii=1; ii < i; ii++){
			TK(output,0,0,i, ii);
		}
	}
	free(output);
	
	return 0;
}





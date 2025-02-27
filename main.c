#include <stdlib.h>
#include <stdio.h>
#include "Bitarray.h"
#include "TrappedKnight.h"

#include <unistd.h>
#include <sys/wait.h>

void print_time(int seconds){
	if(seconds%60<10){
		printf("%d:0%d\n",seconds/60,seconds%60);
	}
	else{
		printf("%d:%d\n",seconds/60,seconds%60);
	}
}

int main(void){
//----------------------------------------------------------------------
//bereite die pipe vor 
	int pipe_ends[2];
//----------------------------------------------------------------------
//bereite denn fork vor	
	pid_t pid = 0;

	pid = fork();
	int* waitstatus;
	
	if(pid == (pid_t)-1){
		exit(EXIT_FAILURE);
	}
	
//----------------------------------------------------------------------
	else if (pid == (pid_t)0){

		int* output = malloc(3*sizeof(int));
	
		for(int i=2; i < 101; i++){
			for(int ii=1; ii < i; ii++){
				TK(output,0,0,i, ii);
			}
		}
		free(output);
	}	
	else{
		int t=0;
		while(0 == waitpid(pid, waitstatus, WNOHANG)){
			//system("clear");
			print_time(t);
			sleep(1);
			t++;
		}
	}
	return 0;
}





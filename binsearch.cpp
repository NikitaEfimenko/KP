#include "stdio.h"
#include <stdlib.h>
#include "math.h"
#include "string.h"


typedef int (*func) (int*, int,int,int);


int iterBS(int* mass, int start, int end, int goal){
	int idx = 0;	
	int size = end + 1;
	int sign = 0;
	for (int i = 0; i < log2(size); ++i){
		idx = start + (end-start)/2;
		sign = mass[idx] - goal;
		if(sign == 0){
			return idx;
		}
		else if ( sign > 0){
			end = idx;
		}
		else{
			start = idx;
		}
	}
	return -1;
}


int recBS(int* mass, int start, int end, int goal){
	int idx = start + (end-start)/2;
	int sign = mass[idx] - goal;
	if(sign == 0){
		return idx;
	}
	if( start == end ){
		return -1;
	}
	return (sign > 0) ? recBS(mass, start, idx, goal) : recBS(mass, idx, end, goal);	
}


void decorator(func f, int *mass, int start,  int end, int goal){
	printf("Search elem = %d in massive...\n", goal);
	int idx = f(mass, start, end, goal);
	if( idx == -1){
		printf("No such elem\n");
	}
	else{
		printf("goal in %d idx\n", idx);
	}

}



int main (int argc, char ** argv){
	int mass[10] = {0, 1, 3, 15, 17, 20 ,123, 436, 3456,10000};
	func f = NULL;
	if (strcmp(argv[1],"iter") == 0)	{
		f = iterBS;
	}
	else if(strcmp(argv[1],"rec") == 0){
		f = recBS;
	}
	decorator(f, mass, 0, 10, atoi(argv[2]));
}
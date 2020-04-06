#include "stdio.h"
#include "stdlib.h"


void load(int * mass, int count){
	for ( int i = 0; i < count; ++i){
		scanf("%d", mass + i);
	}
}


void print(int * mass, int count){
	printf("\n");
	for ( int i = 0; i < count; ++i){
		printf(" %d", *(mass + i));
	}
	printf("\n");
}


void swap( int& a, int &b){
	a = a^b;
	b = a^b;
	a = a^b;
}

void compare(int &a, int &b){
	if (a > b) swap(a,b);
}


void bubbleSort(int* mass, int count){
	for(int i = 1; i < count; ++i){
		for (int j = 0; j < count - i; ++j){
			compare(mass[j], mass[j + 1]);
		}
	}
}

int main(){
	int count;
	int * mass;
	scanf("%d", &count);
	mass = (int *) malloc(4 * count);

	load(mass, count);
	print(mass, count);
	bubbleSort(mass, count);
	print(mass, count);

}
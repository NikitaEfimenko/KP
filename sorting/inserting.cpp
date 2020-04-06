#include <stdio.h>
#include <stdlib.h>


void print(int * mass, int count){
	printf("\n");
	for ( int i = 0; i < count; ++i){
		printf(" %d", *(mass + i));
	}
	printf("\n");
}

void load(int * mass, int count){
	for ( int i = 0; i < count; ++i){
		scanf(" %d", mass + i);
	}
}

void insertingSort(int * mass, int count){
	int j = 0;
	int key;
	for (int i = 1; i < count; ++i){
		j = i - 1;
		key = mass[i];
		while(j >= 0 && key < mass[j]){
			mass[j + 1] = mass[j];
			--j;
		}
		mass[j + 1] = key;
	}
}



int main(int argc, char const *argv[])
{
	int count;
	int * mass;
	scanf("%d", &count);

	mass = (int *) malloc( 4 * count);

	load(mass, count);

	print(mass, count);
	insertingSort(mass, count);
	print(mass, count);

	return 0;
}
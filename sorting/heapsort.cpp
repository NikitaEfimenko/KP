#include "stdio.h"
#include "stdlib.h"

void swap(int& a, int& b){
	a = a^b;
	b = a^b;
	a = a^b;
}

void load(int * mass, int count){
	for (int i = 0; i < count; ++i){
		scanf("%d", mass + i);
	}
}

void print(int * mass, int count){
	printf("\n");
	for (int i = 0; i < count; ++i){
		printf(" %d", *(mass + i));
	}
	printf("\n");
}

void heapify(int * mass, int size, int idx){
	int l = (idx<<1) + 1;
	int r = (idx<<1) + 2;
	int cur = mass[idx];
	int maxId = (l < size && mass[l] > cur) ? l: idx;
	maxId = (r < size && mass[r] > mass[maxId]) ? r: maxId;
	if (maxId != idx){
		swap(mass[maxId], mass[idx]);
		heapify(mass, size, maxId);
	}
}

void buildHeap(int* mass, int size){
	for (int i = size>>1; i >= 0; --i){
		heapify(mass, size, i);
	}
}

void heapSort(int *mass, int size){
	buildHeap(mass, size);
	print(mass, size);
	for (int i = size - 1; i > 0; --i){
		swap(mass[i], mass[0]);
		heapify(mass, i, 0);
	}
}

int main(){
	int count;
	int * mass;
	scanf("%d", &count);
	mass = (int *) malloc( 4 * count);
	load(mass, count);
	print(mass, count);
	heapSort(mass, count);
	print(mass, count);
}
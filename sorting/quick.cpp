#include "stdio.h"



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

void swap(int &a, int&b){
	a = a^b;
	b = a^b;
	a = a^b;
}

void quickSort(int * mass, int st, int end){
	if (st >= end) return;
	int v = mass[(st + end)/2];
	int i = st;
	int j = end;
	while(i < j){
		while(mass[i] < v) ++i;
		while(mass[j] > v) --j;
		if (i >= j) break;
		swap(mass[i++], mass[j--]);
		
	}
	quickSort(mass, st, j);
	quickSort(mass, j + 1, end);
}



int main(){
	int count;
	int* mass;
	scanf("%d", &count);

	load(mass, count);
	print(mass, count);
	quickSort(mass, 0, count - 1);
	print(mass, count);
}
#include "stdio.h"
#include "stdlib.h"

void load(int* mass, int count){
	for (int i = 0; i < count; ++i){
		scanf("%d", mass + i);
	}
}
void print(int* mass, int count){
	printf("\n");
	for (int i = 0; i < count; ++i){
		printf(" %d", *(mass + i));
	}
	printf("\n");
}

void merge(int *mass, int st, int mid, int end){
	int i = 0;
	int j = 0;
	int sz = end - st + 1; 
	int * tmp = (int *) malloc(4 * sz);
	while((st + i) <= mid && (mid + j + 1) <= end){
		if(mass[st + i] < mass[mid + j + 1]){
			tmp[i + j] = mass[st + i];
			++i;
		}
		else{
			tmp[i + j] = mass[mid + j + 1];
			++j; 
		}
	}
	while( (st + i) <= mid){
		tmp[i + j] = mass[st + i];
		++i;
	}
	while( (mid + j + 1) <= end){
		tmp[i + j] = mass[mid + j + 1];
		++j;
	}
	for (int k = 0; k < sz; ++k){
		mass[st + k] = tmp[k];
	}
	free(tmp);
}

void mergeSort(int* mass, int st, int end){
	if(st == end) return;
	int mid = (st + end )/2;
	mergeSort(mass, st, mid);
	mergeSort(mass, mid + 1, end);
	merge(mass, st, mid, end);
}


int main(){
	int count;
	int* mass;
	scanf("%d", &count);
	mass = (int *) malloc(4*count);
	load(mass, count);
	print(mass,count);
	mergeSort(mass, 0, count - 1);
	print(mass,count);
}
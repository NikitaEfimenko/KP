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
		printf(" %d", mass[i]);
	}
	printf("\n");	
}

struct pair{
	int x;
	int y;
};

pair minmax(int * mass, int count){
	int min, max;
	min = 1000000;
	max = -1000000;
	pair res;
	for (int i = 0; i < count; ++i){
		min = (min > mass[i]) ? mass[i]: min;
		max = (max < mass[i]) ? mass[i]: max;
	}
	res.x = min;
	res.y = max;
	return res;
}


void countingSort(int * mass, int count){
	pair minMax = minmax(mass, count);
	int min = minMax.x;
	int max = minMax.y;
	int* tmp = (int *) malloc(4 * (max - min + 1));
	int* tmpRes = (int *) malloc(4 * count);
	for (int i = 0; i < max- min + 1; ++i){
		tmp[i] = 0;
	}
	for (int i = 0; i < count; ++i){
		tmp[mass[i] - min]++;
	}
	for (int i = 1; i < max - min + 1; ++i){
		tmp[i] += tmp[i - 1];
	}
	for (int i = count - 1; i >= 0; --i){
		tmpRes[--tmp[mass[i] - min]] = mass[i];
	}
	for (int i = 0; i < count; ++i){
		mass[i] = tmpRes[i];
	}
	free(tmp);
	free(tmpRes);

}

int main(){
	int count;
	int * mass;
	scanf("%d", &count);
	mass = (int *) malloc(4 * count);

	load(mass, count);
	print(mass,count);
	countingSort(mass, count);
	print(mass, count);	

}
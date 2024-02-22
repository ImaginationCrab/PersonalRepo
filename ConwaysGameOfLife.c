
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int size  = 0;



int deadAlive(int sum,int state){
	if(sum<2||sum>3) return 0;
	if(sum==3) return 1;
	if(sum==2&&state==1) return 1;
	return 0;
}




int checkBounds(int i, int j){
	if(i<size&&j<size&&j>=0&&i>=0){
		return 1;
	}else{
		return 0;
	}
}


int sumCells(int** arr,int i,int j){
	int sum = 0;
	for(int k = -1;k<2;k++){
		for(int m = -1;m<2;m++){
			if(checkBounds(i+k,j+m)&&arr[i+k][j+m]==1&&(k!=0||m!=0)){
				sum++;
			}
		}
	}
	return sum;
}


void nextGen(int** arr){
	int sum = 0;
	for(int i = 0;i<size;i++){
		for(int j = 0;j<size;j++){
			sum = sumCells(arr,i,j);
			arr[i][j] = deadAlive(sum,arr[i][j]);
		}
	}
}


void printGrid(int** arr){
	for(int i = 0;i<size;i++){
		for(int j = 0;j<size;j++){
			if(arr[i][j]==1){
				printf("[#]");
			}else{
				printf("[ ]");
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	int startingCube[5][5] ={};
	startingCube[0][0] = 1;
	startingCube[0][1] = 1;
	startingCube[0][2] = 1;
	startingCube[1][0] = 1;
	startingCube[2][1] = 1;
	



	printf("How big do you want it to be if it is AxA? (has to be at least 6) A = ");
	scanf("%d",&size);
	printf("\n");
	printf("How many generations you want: ");
	int gen = 0;
	scanf("%d",&gen);
	int midpoint = (size-5)/2;
	

	int** arr = calloc(size,sizeof(int*));
	for(int i = 0;i<size;i++){
		arr[i] = calloc(size,sizeof(int));
	}
	for(int i = 0;i<5;i++){
		for(int j = 0;j<5;j++){
			arr[i+midpoint][j+midpoint] = startingCube[i][j];
		}
	}
	for(int i = 0;i<gen;i++){
		printGrid(arr);
		nextGen(arr);
	}
}
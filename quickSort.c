#include <stdio.h>
#include <stdlib.h>


void swap(int* a,int* b){
int temp = *b;
*b = *a;
*a = temp;

}


void printX(int* num,int max){
    for(int i = 0;i<max;i++){
        printf("%d ",num[i]);
    }
}
int partition(int* num,int low,int high){
    int i = low+rand()%(high-low+1);
    swap(&num[low],&num[i]);
    int lowpos = low;
    low++;
    while(low<=high){
        while(low<=high&&num[low]<=num[lowpos])low++;
        while(high>=low&&num[high]>num[lowpos])high--;
        if(low<high){
            swap(&num[low],&num[high]);
        }
    }
    swap(&num[lowpos],&num[high]);
    return high;
}


void quickSort(int* num,int low, int high){
    if(low<high){
        int split = partition(num,low,high);
        quickSort(num,low,split-1);
        quickSort(num,split+1,high);
    }
}

void main(void){
int array[] = {1,23,5,123,2415,213123,616,2,3,4,56,123};    

quickSort(array,0,11);
printX(array,12);
}
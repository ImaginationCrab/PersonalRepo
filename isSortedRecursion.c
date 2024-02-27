#include <stdio.h>
#include <stdlib.h>

int isSorted(int* array,int max,int n){
if(array[n-1]>max){
    return 0;
}
if(n==1){
    return 1;
}
if(array[n-1]>=array[n-2]){
    return isSorted(array,max,--n);
}else{
    return 0;
}

}


void main(void){
int array[] = {3,6,7,7,12};
int b[] = {3,4,9,8};
printf("%d %d ",isSorted(array,12,5),isSorted(b,20,4));



}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Alexander Ge Programming Assignment 2
2/21/2024
*/


//global variables
int size;
char* arr[50];
int popcorn[50];
char* pair[2][50];
int pairs;
int count = 0;

//swap function (swaps strings and ints at the same time)
void swap(int a, int b){
    int tempInt = popcorn[a];
    char* tempString = arr[a];
    arr[a] = arr[b];
    arr[b] = tempString;
    popcorn[a] = popcorn[b];
    popcorn[b] = tempInt;
}


//checks if the requested spot is within the bounds
int checkBounds(int a){
    if(a>=0&&a<size)
    return 1;
    return 0;
}
//checks if the person is holding popcorn or is next to someone with popcorn
int popcornStatus(int a){

        for(int k = -1;k<2;k++){
            if(checkBounds(a+k)==1&&popcorn[a+k]==1){
                return 1;
            }
        }
        return 0;
}
//only runs if there is a pair and checks the people next to the given spot to see if a pair is a match, if it is a match return true
int checkNext(int a,char* str){
    if(checkBounds(a-1)==1){
        if(strcmp(arr[a-1],str)==0){
            return 1;
        }
    }
    if(checkBounds(a+1)==1){
        if(strcmp(arr[a+1],str)==0){
            return 1;
        }
    }
    return 0;
}
//runs through the entire current permutation and checks if the popcorn status is valid and if there are any pairs that shouldn't be next to eachother
int checkValid(){
    for(int i = 0;i<size;i++){
        //popcorn status check for each individual
        if(popcornStatus(i)==0){
            return 0;
        }
        //checks if any individual is in the pairs[][] array, if true then run the checkNext() method passing the other member of the pair
        //if both statements are true, then the permutation is not valid
        for(int j = 0;j<pairs;j++){
            if(strcmp(arr[i],pair[0][j])==0&&checkNext(i,pair[1][j])){
                return 0;
            }
            if(strcmp(arr[i],pair[1][j])==0&&checkNext(i,pair[0][j])){
                return 0;
            }

        }
    }
    //returns 1 if all conditions are met
    return 1;
}
//print Permutation
void printPerm(){
    for(int i = 0;i<size;i++){
        
        printf("%s\n",arr[i]);
    }
    printf("\n");
}

//permutation algorithm
void permute(int starting,int length){
    
    int i;
    if(length==starting){
        
        if(checkValid()==1&&count==0){
            printPerm();
            count++;
        }
    }
    for(i = starting;i<length;i++){
        swap(starting,i);
        permute(starting+1,length);
        swap(starting,i);
    }
}


//main to setup the program
//Use the format: .\wheretositb.exe wheretosit#.in
//to run the program
int main(int argc, char*argv[]){
    FILE *fp = fopen(argv[1], "r");
    fscanf(fp,"%d %d",&size,&pairs);
    for(int i = 0;i<size;i++){
        arr[i] = calloc(100,sizeof(char));
        fscanf(fp,"%s %d",arr[i],&popcorn[i]);
    }
    for(int i = 0;i<pairs;i++){
        pair[0][i] = calloc(100,sizeof(char));
        pair[1][i] = calloc(100,sizeof(char));
        fscanf(fp,"%s %s",pair[0][i],pair[1][i]);
    }
    permute(0,size);
    
    
    fclose(fp);

}
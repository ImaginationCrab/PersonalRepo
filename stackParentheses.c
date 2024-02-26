#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    char data;
    struct stack* next;
}stack;
void pop(stack** head){
    if(*head==NULL)return;
    if((*head)==NULL){
        free(*head);
        return;
    }
    free((*head));
}


void push(stack** head,char data){
    stack* new = calloc(1,sizeof(stack));
    stack* temp = *head;
    new->data = data;
    new->next = NULL;
    if(temp==NULL){
        temp = new;
        free(new);
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new;
    
}

void main(void){
char arr[50];
scanf("%s",arr);
stack* head = NULL;
for(int i = 0;i<50;i++){
    if(arr[i]=='('){
        push(&head,'(');
    }
    if(arr[i]==')'){
        pop(&head);
    }
}
if(head!=NULL){
    printf("Not balanced");
}else{
    printf("Balanced");
}


}
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    char data;
    struct stack* next;
    struct stack* back;
}stack;
void pop(stack** head){
    if(*head==NULL)return;
    if((*head)->back!=NULL){
        *head = (*head)->back;
        *head = NULL;
        free((*head)->next);
        return;
    }
    *head = NULL;
    free((*head));
}


void push(stack** head,char data){
    stack* new = calloc(1,sizeof(stack));
    new->data = data;
    new->next = NULL;
    new->back = NULL;
    if(*head==NULL){
        *head = new;
        return;
    }
    new->back = *head;
    (*head)->next = new;
    *head = (*head)->next;

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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 19
typedef struct customer{
    char name[MAXLEN+1];
    int points;
}customer;
typedef struct treenode{
    customer* cPtr;
    int size;
    struct treenode* left;
    struct treenode* right;
}treenode;

struct treenode* findName(char* str, treenode** head){
    treenode* temp = *head;
    if(temp==NULL){
        return NULL;
    }
    int val = strcmp(str,temp->cPtr->name);
    while(val!=0){
        if(val>0){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
        if(temp==NULL){
            return NULL;
        }
        val = strcmp(str,temp->cPtr->name);
    }
    return temp;
}
// this is add but linearly instead of recursively
// void add(char* str, int pts, treenode** head){
//     treenode* temp = *head;
//     treenode* new = (treenode*)calloc(1,sizeof(treenode));
//     customer* tempcustomer = (customer*)calloc(1,sizeof(customer));
//     tempcustomer->points = pts;
//     strcpy(tempcustomer->name,str);
//     new->cPtr = tempcustomer;
//     while(temp!=NULL){
//         char* tempstr = temp->cPtr->name;
//         int value = strcmp(str,tempstr);
//         if(value>0){
//             if(temp->right==NULL){
//                 temp->right = new;
//                 return;
//             }
//             temp =temp->right;
//         }else{
//             if(temp->left==NULL){
//                 temp->left = new;
//                 return;
//             }
//             temp = temp->left;
//         }
//     }
//     *head = new;
// }

struct treenode* insert(treenode* root, treenode* element){
    if(root==NULL){
        return element;
    }
    else{
        int val = strcmp(element->cPtr->name,root->cPtr->name);
        if(val>0){
            if(root->right!=NULL){
                root->right = insert(root->right,element);
            }else{
                root->right = element;
            }
        }else{
            if(root->left!=NULL){
                root->left = insert(root->left, element);
            }else{
                root->left = element;
            }
        }
    }
    return root;
}
void add(char* str, int pts, treenode** head){
    treenode* temp = *head;
    treenode* new = (treenode*)calloc(1,sizeof(treenode));
    customer* tempcustomer = (customer*)calloc(1,sizeof(customer));
    tempcustomer->points = pts;
    strcpy(tempcustomer->name,str);
    new->cPtr = tempcustomer;
    *head = insert(*head,new);//why in the world does this work???????
}

void sub(char* str,int subpts,treenode** head){
    treenode* node = findName(str,head);
    treenode* temp = node;
    if(subpts>=temp->cPtr->points){
        temp->cPtr->points = 0;
        return;
    }
    temp->cPtr->points -= subpts;
}

void main(void){
treenode* head = NULL;
add("what",30,&head);
if(head==NULL){
    printf("add is not working");
}else{
    printf("add is working");
}
add("bruh",30,&head);
printf("%s",head->cPtr->name);
sub("what",25,&head);
printf("%d",head->cPtr->points);
}
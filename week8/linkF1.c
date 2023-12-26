#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int flag;
    struct node* next;
};

int loopcheck(struct node** head){
    if(!(*head)){
        return 0;
    }
    struct node*temp=*head;
    while(temp){
        if(temp->flag==1){
            printf("cycle is present");
            return 1;
        }
        temp->flag=1;
        temp=temp->next;
    }
    if(!(temp)){
        printf("cycle is not present");
        return 0;
    }
}

int main(){
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* m1=(struct node*)malloc(sizeof(struct node));
struct node* tail=(struct node*)malloc(sizeof(struct node));
head->data=3;
head->next=m1;
head->flag=NULL;
m1->data=4;
m1->next=tail;
m1->flag=NULL;
tail->data=5;
tail->next=NULL;
//tail->next=m1;
tail->flag=NULL;
loopcheck(&head);
return 0;
}


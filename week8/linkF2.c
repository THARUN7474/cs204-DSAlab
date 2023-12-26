#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int init(struct node **head){
    *head=NULL;//its set to null
    printf("initializing linkedlist\n");
    return 1;
}

int insert(struct node **head,int pos,int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("out of memory\n");
        return 0;
    }
    newnode->data=data;
   
    if(pos==1){
        newnode->next=*head;
        *head=newnode;
        return 1;
    }
    struct node*pre=*head;
    for( int i=1; pre->next!=NULL && i<pos-1 ;i=i+1){
        pre=pre->next;
    }
    if(!pre){
        return 0;
    }
    else{
        newnode->next=pre->next;
        pre->next=newnode;
        return 1;
    }
}

int traverse(struct node **head){
    struct node*ptr;
    for(ptr=*head;ptr;ptr=ptr->next){
        printf("%d ",ptr->data);
    }
    printf("NULL\n");
    return 1;
}

int linkcheck(struct node **head){
    struct node*p1=*head;
    struct node*p2=NULL;
    while(p1){
        p2=*head;
        while(p1!=p2){
            // printf("%d\n",p1->data);
            // printf("%d\n",p2->data);
            if(p1->next==p2){
                printf("yes the link is ffound\n");
                return 1;
            }
            p2=p2->next;
        }
        if(p1->next==p2){
            printf("yes the link is found\n");
            return 1;
        }
        p1=p1->next;
    }
    printf("no the link is not found\n");
    return 0;
}
int main(){
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* m1=(struct node*)malloc(sizeof(struct node));
struct node* tail=(struct node*)malloc(sizeof(struct node));
head->data=3;
head->next=m1;
m1->data=4;
m1->next=tail;
tail->data=5;
tail->next=NULL;
//tail->next=m1;
traverse(&head);
linkcheck(&head);
return 0;
}
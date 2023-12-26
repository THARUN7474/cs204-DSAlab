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

int reverse(struct node**head){
    if(*head==NULL){
        return 1;
    }
    struct node *p1,*p2,*p3;
    p1=*head;
    if(p1!=NULL){
        p2=p1->next;
    }
    if(p2!=NULL){
        p3=p2->next;
    }
    p1->next=NULL;
    while(p2!=NULL){
        p2->next=p1;
        p1=p2;
        p2=p3;
        if(p3!=NULL){
            p3=p3->next;
        }
        else{
            p3=NULL;
        }
    }
    *head=p1;
    return 1;
}

int main(){ 
    struct node *head;
    init(&head);
    insert(&head,1,10);
    insert(&head,1,20);
    insert(&head,1,30);
    insert(&head,1,40);
    insert(&head,1,50);
    insert(&head,1,60);
    printf("the linkedlist before reverseing:");
    traverse(&head);
    reverse(&head);
    printf("the linkedlist after reverseing:");
    traverse(&head);
    return 0;
}

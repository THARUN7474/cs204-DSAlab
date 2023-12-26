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

int deleteItem(struct node **head, int datac){
    struct node*current=*head;   
    struct node*pre=NULL;
    while(current && current->data!=datac){
        pre=current;
        current=current->next;
    }
    if(!current){
         return 0;
    }
    if(!pre){
        *head=(*head)->next;
        free(current);
        return 1;
    }
    else{
        pre->next=current->next;
        free(current);
        return 1;
    }
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
    printf("the linkedlist before deleting:");
    traverse(&head);
    deleteItem(&head,50);
    printf("the linkedlist after deleting:");
    traverse(&head);
    return 0;
}


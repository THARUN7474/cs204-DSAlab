#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int init(struct node**head){
    *head=NULL;
}

int insert(struct node**head,int datatoinsert){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        return 0;
    }//insertion only at 1st position
    newnode->data=datatoinsert;
    newnode->next=(*head);
    *head=newnode;
    return 1;
}
int traverse(struct node**head){
    struct node*ptr=*head;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("null\n");
    return 1;
}

int insertafterdatag(struct node**head,int dataI){
    struct node*ptr1;
    struct node*ptr2;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("no space");
        return 0;
    }
    newnode->data=dataI;
    if(*head==NULL){
        newnode->next=NULL;
        *head=newnode;
        return 1;
    }
    ptr1=*head;
    ptr2=NULL;
    while(ptr1!=NULL && (ptr1->data)<dataI){
        ptr2=ptr1;
        ptr1=ptr1->next;
    }
    if(ptr1==NULL){
        ptr2->next=newnode;
        newnode->next=NULL;
        return 1;
    }
    ptr2->next=newnode;
    newnode->next=ptr1;
    return 1;
}

int main(){
    int data,A,B;
    struct node*head;//declaration of head pointer to use
    init(&head);
    printf("\nenter the data to insert;");
    scanf("%d",&data);
    printf("\nenter the number of elements u want to insert:");
    scanf("%d",&A);
    for(int i=0;i<A;i++){
        printf("\nenter the int element to insert(enter in decreasing order(40 then 30...))");
        scanf("%d",&B);
        insert(&head,B);
    }
    printf("\nthe LL before insertion of given int element\n");
    traverse(&head);
    insertafterdatag(&head,data);
    printf("\nthe LL after insertion of given int element\n");
    traverse(&head);
    return 0;
}

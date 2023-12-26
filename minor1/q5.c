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
int traverse(struct node**head,int *C){
    struct node*ptr=*head;
    int c=0;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        c=c+1;
        ptr=ptr->next;
    }
    *C=c;
    printf("null\n");
    return 1;
}
int deletehalf(struct node**head,int *c){
    struct node*ptr1=*head;
    struct node*ptr2=NULL;
    // printf("%d",c);----address of c
    // printf("%d",*c);-----value of c
    for(int i=0;i<(*c)/2 && ptr1!=NULL;i++){
        ptr2=ptr1;
        ptr1=ptr1->next;
        *head=ptr1;
        free(ptr2);
    }
    return 1;
}

int main(){
    int data,A,B,c;
    struct node*head;
    init(&head);
    printf("\nenter the (even) number of elements u want to insert:");
    scanf("%d",&A);
    printf("\nenter the int element to insert(enter in decreasing order(40 then 30...))");
    for(int i=0;i<A;i++){
        scanf("%d",&B);
        insert(&head,B);
    }
    printf("\nthe LL before deletion of elements\n");
    traverse(&head,&c);
    printf("\nthe LL after deletion\n");
    //printf("c is %d\n",c);
    deletehalf(&head,&c);
    traverse(&head,&c);
    return 0;
}
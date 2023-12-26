#include<stdio.h>
#include<stdlib.h>

struct nodeLLL{
    int D1;
    int D2;
    struct nodeLLL*next;
};

int init(struct nodeLLL**head){
    *head=NULL;
    return 1;
}
int insert(struct nodeLLL**head,int datain){
    struct nodeLLL*newnode=(struct nodeLLL*)malloc(sizeof(struct nodeLLL));
    if(!newnode){
        return 0;
    }
    newnode->D1=datain;
    newnode->D2=NULL;
    newnode->next=(*head);
    *head=newnode;
    return 1;
}
int linkupLL_CLL(struct nodeLLL**head,int pos){
    struct nodeLLL*ptr=*head;
    struct nodeLLL*ptr1=*head;
    if(*head=NULL){
        return 0;
    }
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    int i=1;
    for(i=1;ptr1!=NULL && i<(pos)-1;i++){
        ptr1=ptr1->next;
    }
    printf("%d\t",i);
    if(i==pos-1){
        ptr->next=ptr1->next;//linking up so that SLL is converted to cll
        *head=ptr;
        printf("linked successfully\n");
        return 1;
    }
}
int traverse(struct nodeLLL **head){
    struct nodeLLL*ptr;
    for(ptr=*head;ptr;ptr=ptr->next){
        printf("%d ",ptr->D1);
    }
    printf("NULL\n");
    return 1;
}

int traversal(struct nodeLLL**head){
    struct nodeLLL*ptr=*head;
    if(*head==NULL){
        printf("\nthe list is empty\n");
        return 0;
    }
    do{
        printf("%d->",ptr->D1);
        ptr=ptr->next;
    }while(ptr!=*head);
    return 1;
}
int main(){
    int N,a,M;
    struct nodeLLL*head;
    init(&head);
    insert(&head,40);
    printf("enter the no of elements to insert");
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        printf("enter the element to insert");
        scanf("%d",&a);
        insert(&head,a);
    }
    traverse(&head);
    printf("enter the position to link");
    scanf("%d",&M);
    linkupLL_CLL(&head,M);
    traversal(&head);
    return 0;
}
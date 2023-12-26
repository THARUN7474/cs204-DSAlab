#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"


int main(){
    int data;
    struct node*head;//declaration of head pointer to use
    struct node*ptrTokey=NULL;
    init(&head);
    insert(&head,1,10);
    insert(&head,2,20);
    insert(&head,3,30);
    traverse(&head);
    insertafter(&head,40,60);
    traverse(&head);
    insertafter(&head,30,60);
    traverse(&head);
    insertbefore(&head,30,70);
    traverse(&head);
    search(&head,20,&ptrTokey);
    deleteItem(&head,30);
    traverse(&head);
    deleteByPosition(&head,2,&data);
    traverse(&head);
    destroy(&head);
    traverse(&head);
    return 0;

}



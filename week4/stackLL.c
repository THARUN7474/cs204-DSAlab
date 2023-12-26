#include<stdio.h>
#include<stdlib.h>
//#include"linkedlist.h"...here it is already included in stackLL.h header file so no need ..if we inlcude it collides duplicates form
#include"stackLL.h"


int init(struct stackL*sptr){
    sptr->head=NULL;
    printf("stack LINKEDLIST is initialised\n");
    return 1;
}

int isEmpty(struct stackL*sptr){
    if(sptr->head==NULL){
        printf("stack LINKED LIST  is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stackL*sptr){
    //here heap is full or not thats need to check so we use malloc call to check
    //if it is full so no dynamic memory allocation occurs
    struct node*dptr=(struct node*)malloc(sizeof(struct node));
    if(dptr==NULL){
        return 1;
    }
    else{
        free(dptr);
        return 0;
    }
}

int push(struct stackL*sptr,int data){
    if((isFull(sptr))){
        printf("IT IS full so cant push\n");
        return 0;
    }
    int b;
    b=insert(&(sptr->head),1,data);
    return 1;
}
int pull(struct stackL*sptr,int *data){
    if((isEmpty(sptr))){
        printf("its is empty so cant pull\n");
        return 0;
    }
    *data=(sptr->head)->data;
    sptr->head=(sptr->head)->next;
    printf("poped out element is %d\n",*data);
    return 1;
}

int peek(struct stackL*sptr,int *data){
    if((isEmpty(sptr))){
        printf("its is empty so cant peek\n");
        return 0;
    }
    *data=(sptr->head)->data;
    printf("the element that top of stackLL is %d\n",*data);
    return 1;
}

int destroy(struct stackL*sptr){
    int c;
    c=destroy(&(sptr->head));
    printf("it is destroyed\n");
    return 1;
}


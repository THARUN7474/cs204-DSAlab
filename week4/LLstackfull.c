#include<stdio.h>
#include<stdlib.h>
//#include"linkedlist.h"...here it is already included in stackLL.h header file so no need ..if we inlcude it collides duplicates form
#include"linkedlist.h"

struct stackL{
    struct node*head;
};


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
        printf("IT IS full so cant push");
        return 0;
    }
    struct node *old;
    old=sptr->head;
    sptr->head=(struct node *)malloc(sizeof(struct node));
    ((sptr->head)->data)=data;
    ((sptr->head)->next)=old;
    //printf("%d is inserted into stack\n", data);
    return 1;
    /* int b;
    b=insert(&(sptr->head),1,data);
    return 1; */
}

int pull(struct stackL*sptr,int *data){
    if((isEmpty(sptr))){
        printf("its is empty so cant pull");
        return 0;
    }
    *data=(sptr->head)->data;
    sptr->head=(sptr->head)->next;
    printf("poped out element is %d\n",*data);
    return 1;
}

int peek(struct stackL*sptr,int *data){
    if((isEmpty(sptr))){
        printf("its is empty so cant peek");
        return 0;
    }
    *data=(sptr->head)->data;
    printf("the element that top of stackLL is %d\n",*data);
    return 1;
}

int destroy(struct stackL*sptr){
    int c;
    c=destroy(&(sptr->head));
    printf("it is destroyed");
    return 1;
}
/* int pull(struct stackL*sptr,int *data){
    if((isEmpty(sptr))){
        printf("its is empty so cant pull");
        return 0;
    }
    int a;
    a=deleteByPosition(&(sptr->head),1,data);
    return 1;
}

int peek(struct stackL*sptr,int *data){
    if((isEmpty(sptr))){
        printf("its is empty so cant peek");
        return 0;
    }
    *data=(sptr->head)->data;
    return 1;
}

int destroy(struct stackL*sptr){
    int c;
    c=destroy(&(sptr->head));
    printf("it is destroyed");
    return 1;
}
 */
int main(){
    struct stackL scall;
    int dataout;
    printf("hello\n\n");
    init(&scall);
    isEmpty(&scall); 
    isFull(&scall);
    int F;
    printf("enter the no of elemenst u want to push in ");
    scanf("%d",&F);
    for(int i=0;i<F;i++){
        int a;
        printf("enter the data to push into stack array");
        scanf("%d",&a);
        push(&scall,a);
    }
    peek(&scall,&dataout);//here as stack follows LIFO we get last enterted data 
    for(int i=F;i>0;i--){
        pull(&scall,&dataout);
    }
    destroy(&scall);
    isEmpty(&scall);
    return 0;
}
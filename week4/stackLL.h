#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

struct stackL{
    struct node*head;
};

int init(struct stackL*sptr);
int isEmpty(struct stackL*sptr);
int isFull(struct stackL*sptr);
int push(struct stackL*sptr,int data);
int pull(struct stackL*sptr,int *data);
int peek(struct stackL*sptr,int *data);
int destroy(struct stackL*sptr);

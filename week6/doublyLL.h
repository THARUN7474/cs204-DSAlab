#include<stdio.h>
#include<stdlib.h>

struct nodeLL{
    int data;
    struct nodeLL *next;
    struct nodeLL *prev;
};

int init(struct nodeLL **head,struct nodeLL **tail);
int insertatposition(struct nodeLL **head,struct nodeLL **tail,int datatoinsert ,int pos);
int deletebyelement(struct nodeLL **head,struct nodeLL **tail,int datatodelete);
int search(struct nodeLL **head,struct nodeLL **tail,int datatofind);
int traverseforward(struct nodeLL **head);
int traversebackward(struct nodeLL **tail);
int finding_small_large(struct nodeLL **head,struct nodeLL **tail,int *smallp,int *largep);

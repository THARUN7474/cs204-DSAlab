#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int init(struct node**tail);
int insertafter(struct node**tail,int dataTI,int Adata);
int deleteitem(struct node**tail,int dataTD);
int search(struct node**tail,int dataTS);
int traversal(struct node**tail);
int destroy(struct node**tail);
#define SIZE 1000
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int arr[SIZE];
    int top;
};

int init(struct stack *s);
int destroy(struct stack *s);
int isEmpty(struct stack *s);
int isFull(struct stack *s);
int push(struct stack *s,int datain);
int pop(struct stack *s,int *dataout);
int peek(struct stack *s,int *dataout);


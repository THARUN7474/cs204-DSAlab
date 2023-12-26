#include<stdio.h>
#include<stdlib.h>
#include"Astack.h"

int init(struct stack *s){
    s->top=-1;//initialization of array stack .. here top is used to accesss position of elements of arr
    printf("\nnew stack ARR formed\n");
    return 1;
}

int destroy(struct stack *s){
    s->top=-1;// here arr gets empty ...as top is one set to -1 means no elements
    printf("stack ARR is destroyed\n");
    return 1;
}

int isEmpty(struct stack *s){
    if(s->top==-1){
        printf("stack ARR is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *s){
    if(s->top==SIZE-1){
        printf("stack ARR is full\n");
        return 1;}
    else{
        return 0;}
}

int push(struct stack *s,int datain){
    if((isFull(s))){
        printf("cant push as it is already full\n");
        return 0;
    }
    (s->top)++;
    s->arr[s->top]=datain;
    return 1;
}

int pop(struct stack *s,int *dataout){
    if((isEmpty(s))){
        printf("cant pop as it is already empty\n");
        return 0;
    }
    *dataout=s->arr[s->top];
    (s->top)--;
    return 1;
}

int peek(struct stack *s,int *dataout){
    if((isEmpty(s))){
        printf("cant peek as it is already empty\n");
        return 0;
    }
    *dataout=s->arr[s->top];
    return 1;
}




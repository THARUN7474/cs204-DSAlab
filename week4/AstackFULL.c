#define SIZE 100
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int arr[SIZE];
    int top;
};

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
        printf("can not push as it is full\n");
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

int main(){
    struct stack scall;
    int dataout;
    printf("hello");
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
    isEmpty(&scall);
    peek(&scall,&dataout);//here as stack follows LIFO we get last enterted data 
    printf("%d\n",dataout);
    while(!(isEmpty(&scall))){
        pop(&scall,&dataout);
        printf("%d\t",dataout);
    }
    destroy(&scall);
    isEmpty(&scall);
    return 0;
}

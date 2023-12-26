#include<stdio.h>
#include<stdlib.h>
#include"Astack.h"

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
#include<stdio.h>
#include<stdlib.h>
#include"stackLL.h"

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
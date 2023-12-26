#include<stdio.h>
#include<stdlib.h>

int main(){
    for(int i =0;i<10;i++){
        if(i<3)
        printf("hello");
        else
        printf("hi");
    }
    printf("enter the no of elemenst u want to push in ");
    for(int i=0;i<5;i++){
        int a;
        printf("\nenter the data to push into stack array\n");
        scanf("%d",&a);
        printf("%d\t",a);
    }
    int F;
    printf("enter the no of elemenst u want to push in ");
    scanf("%d",&F);
    for(int i=0;i<F;i++){
        int a;
        printf("enter the data to push into stack array");
        scanf("%d",&a);
        push(scall,a);
    }
    peek(scall,&dataout);//here as stack follows LIFO we get last enterted data 
    printf("%d\t",dataout);
    while(!(isEmpty(scall))){
        pop(scall,&dataout);
        printf("%d\t",dataout);
    }
    struct stack scall;
    int data;
    printf("hello");
    init(&scall);
    isEmpty(&scall);
    isFull(&scall);
    push(&scall,1);
    push(&scall,2);
    push(&scall,3);
    peek(&scall,&data);
    printf("\n%d\t",data);
    pop(&scall,&data);
    printf("\n%d\t",data);
    isEmpty(&scall);
    isFull(&scall);
    return 0;
    return 0;
}

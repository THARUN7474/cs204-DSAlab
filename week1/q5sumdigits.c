#include<stdio.h>

int main() {
    int a,b,c,d;
    b=c=0;
    printf("enter the number1 a:");
    scanf("%d" ,&a);
    while(a>0){
        d=a%10;
        a=a/10;
        b=b+d;
        c=c+1;
    }
    printf("the no of digits of a: %d and sum of digits of a : %d",c,b);

    return 0;
}
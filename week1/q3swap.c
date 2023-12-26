#include<stdio.h>

int main() {
    //with temporary variable
    int a,b,t;
    printf("enter the number1 a:");
    scanf("%d" ,&a);
    printf("enter the number2 b:");
    scanf("%d" ,&b);
    t=a;
    a=b;
    b=t;
    printf("new a: %d and b: %d\n\n",a,b);

    //with out temporary varaible
    int c,d;
    printf("enter the number1 c:\n");
    scanf("%d" ,&c);
    printf("enter the number2 d:\n");
    scanf("%d" ,&d);
    c=c+d;
    d=c-d;
    c=c-d;
    printf("new c: %d and d: %d\n",c,d);

    return 0;
}

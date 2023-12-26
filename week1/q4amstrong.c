#include<stdio.h>
#include<math.h>

int main() {
    int a,c,d;
    c=0;
    printf("enter the number1 a:");
    scanf("%d" ,&a);
    int i;
    double J;
    J=a;
    i=a;
    while(a>0){
        d=a%10;
        a=a/10;
        c=c+1;
    }
    printf("%d,%d,%lf\n",c,i,J);
    double A,K,C;
    C=c;
    while(i>0){
        K=i%10;
        i=i/10;
        A=A+pow(K,C);
    }
    printf("%lf\n\n",A);
    if(A==J){
        printf("the given number \"a\" is amstrong number\n\n");
    }
    else{
        printf("the given number \"a\" is not amstrong number\n\n");
    }
    return 0;
}
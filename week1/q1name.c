#include<stdio.h>

int main() {
    char name[30];
    int r;
    printf("enter your name:");
    scanf("%s", name);
    printf("enter your roll number:");
    scanf("%d", &r);
    printf(" my name is %s and my roll number is %d",name,r);
    return 0;
    
}
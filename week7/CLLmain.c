#include<stdio.h>
#include<stdlib.h>
#include"CLL.h"

int main(){
    int data1,data2,small;
    int N,m,a,b,c,d,p;
    struct node *tail;
    init(&tail);
    printf("\nenter the no of elements to insert");
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        printf("\nenter the element to insert");
        scanf("%d",&a);
        printf("\nenter the element to isnert after(before enterted element):");
        scanf("%d",&c);
        insertafter(&tail,a,c);
    }
    traversal(&tail);

    printf("\nenter the no of elements to insert");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("\nenter the element to insert");
        scanf("%d",&b);
        printf("\nenter the element that to be as refernece to insert;");
        scanf("%d",&p);
        insertafter(&tail,b,p);
    }
    traversal(&tail);
    printf("\nenter the element to delete");
    scanf("%d",&d);
    deleteitem(&tail,d);
    traversal(&tail);
    printf("\nenter the element to search");
    scanf("%d",&data1);
    search(&tail,data1);
    traversal(&tail);
    destroy(&tail);
    traversal(&tail);
    return 0;
}
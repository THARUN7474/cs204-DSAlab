#include<stdio.h>
#include<stdlib.h>
#include"doublyLL.h"

int main(){
    int data1,data2,smallest,largest;
    int N,a,m,b,D,p;
    struct nodeLL *head;
    struct nodeLL *tail;
    init(&head,&tail);
    printf("enter the no of elements to insert");
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        printf("enter the element to insert");
        scanf("%d",&a);
        insertatposition(&head,&tail,a,1);
        traverseforward(&head);
    }
    traverseforward(&head);
    traversebackward(&tail);

    printf("enter the no of elements to insert");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("enter the element to insert");
        scanf("%d",&b);
        printf("enter the position to insert");
        scanf("%d",&p);
        insertatposition(&head,&tail,b,p);
    }
    traverseforward(&head);
    traversebackward(&tail);
    printf("enter the element to search");
    scanf("%d",&data1);
    search(&head,&tail,data1);
    traverseforward(&head);
    traversebackward(&tail);
    printf("enter the  element to delete");
    scanf("%d",&D);
    deletebyelement(&head,&tail,D);
    traverseforward(&head);
    traversebackward(&tail);
    finding_small_large(&head,&tail,&smallest,&largest);
    printf("the smallest in DLL is %d,the largest in DLL is %d",smallest,largest);
    return 0;
}

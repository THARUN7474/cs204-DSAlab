#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int FSptr(struct node**head){
    struct node *ps=*head;
    struct node *pf=head?ps->next:NULL;
    if(!(*head)){
        return 0;
    }
    while(ps!=pf){
        // printf("%d\n",ps->data);
        // printf("%d\n",pf->data);
        ps=ps->next;
        if(pf){
            pf=pf->next;
        }
        else{
            printf("no link\n");
            return 0;
        }
        if(pf){
            pf=pf->next;
        }
        else{
            printf("no link\n");
            return 0;
        }
    }
    printf("yes link found\n");
    return 1;
}
int main(){
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* m1=(struct node*)malloc(sizeof(struct node));
struct node* tail=(struct node*)malloc(sizeof(struct node));
head->data=3;
head->next=m1;
m1->data=4;
m1->next=tail;
tail->data=5;
tail->next=NULL;
//tail->next=m1;
//traverse(&head);
FSptr(&head);
return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int init(struct node**tail){
    *tail=NULL;
    return 1;
}

int insertafter(struct node**tail,int dataTI,int Adata){
    struct node*ptr=*tail;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        return 0;
    }
    newnode->data=dataTI;
    if(*tail==NULL){
        newnode->next=newnode;
        *tail=newnode;
        return 1;
    }
    else{
        do{
            if(ptr->data==Adata){
                newnode->next=ptr->next;
                ptr->next=newnode;
                return 1;
            }
            ptr=ptr->next;
        }while(ptr!=*tail);
        return 0;
    }
}

int traversal(struct node**tail){
    struct node*ptr=*tail;
    if(*tail==NULL){
        printf("the list is empty");
        return 0;
    }
    do{
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=*tail);
    return 1;
}

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
}
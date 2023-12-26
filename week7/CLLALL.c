#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

int init(struct node**tail);
int insertafter(struct node**tail,int dataTI,int Adata);
int deleteitem(struct node**tail,int dataTD);
int search(struct node**tail,int dataTS);
int traversal(struct node**tail);
int destroy(struct node**tail);



// ................................................
// #include<stdio.h>
// #include<stdlib.h>
// #include"circularLL.h"



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
int deleteitem(struct node**tail,int dataTD){
    struct node*ptr=*tail;
    struct node*fptr=NULL;
    if(*tail==NULL){
        printf("the list is empty\n");
        return 0;
    }
    fptr=ptr->next;
    do{
        if(fptr->data=dataTD){
            ptr->next=fptr->next;
        }
        if(ptr==fptr){
            *tail=NULL;
        }
        if(*tail==fptr){
            *tail=ptr;
        }
        free(fptr);
        return 1;
        ptr=fptr;
        fptr=ptr->next;
    }while(ptr!=*tail);
    printf("the given element not found\n");
    return 0;
}

int search(struct node**tail,int dataTS){
    struct node*ptr=*tail;
    if(*tail==NULL){
        printf("the list is empty\n");
        return 0;
    }
    do{
        if(ptr->data==dataTS){
            printf("data is found\n");
            return 1;
        }
        ptr=ptr->next;
    }while(ptr!=*tail);
    printf("the element is not found\n");
    return 0;
}

int traversal(struct node**tail){
    struct node*ptr=*tail;
    if(*tail==NULL){
        printf("\nthe list is empty\n");
        return 0;
    }
    do{
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=*tail);
    return 1;
}

int destroy(struct node**tail){
     struct node*ptr=NULL;
    if(*tail==NULL){
        printf("NO CLL\n");
        return 1;
    }
    do{
        ptr=(*tail)->next;
        (*tail)->next=ptr->next;
        if(*tail==ptr){
            *tail=NULL;//here it will be for last presnet node(single node loop to itself)
        }
        free(ptr);
        ptr=ptr->next;
    }while(*tail!=NULL);
    return 1;
}

// ...................................................
// #include<stdio.h>
// #include<stdlib.h>
// #include"circularLL.h"

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
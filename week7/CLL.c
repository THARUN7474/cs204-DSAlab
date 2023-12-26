#include<stdio.h>
#include<stdlib.h>
#include"CLL.h"

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
        if(fptr->data==dataTD){
            ptr->next=fptr->next;
            free(fptr);
            return 1;
        }
        if(ptr==fptr){
            *tail=NULL;
            free(fptr);
            return 1;
        }
        if(*tail==fptr){
            *tail=ptr;
            ptr->next=*tail;
            free(fptr);
            return 1;
        }
        ptr=fptr;
        fptr=ptr->next;
    }while(ptr!=*tail);
    printf("the given element not found\n");
    return 0;
}

int search(struct node**tail,int dataTS){
    struct node*ptr=*tail;
    int c=1;
    if(*tail==NULL){
        printf("the list is empty\n");
        return 0;
    }
    do{
        if(ptr->data==dataTS){
            printf("data(%d) is found at position(%d)\n",dataTS,c);
            return 1;
        }
        ptr=ptr->next;
        c++;
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
        //ptr=ptr->next;
    }while(*tail!=NULL);
    printf("\nCLL is destroyed\n");
    return 1;
}


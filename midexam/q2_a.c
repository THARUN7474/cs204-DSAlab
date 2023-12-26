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
int insertbefore(struct node**tail,int dataTI,int Bdata){
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
            if((ptr->next)->data==Bdata){
                newnode->next=ptr->next;
                ptr->next=newnode;
                return 1;
            }
            ptr=ptr->next;
        }while(ptr!=*tail);
        return 0;
    }
}


int main(){
    int data1,data2,small;
    int N,m,a,b,c,d,p;
    struct node *tail;
    init(&tail);
    insertafter(&tail,10,0);    
    insertafter(&tail,20,10);    
    insertafter(&tail,30,20);    
    insertafter(&tail,40,30);    
    insertafter(&tail,50,40);    
    insertafter(&tail,60,50);   
    printf("the circularlinkedlist:");
    traversal(&tail);
    printf("\n");
    insertafter(&tail,80,50); 
    printf("the circularlinkedlist after inserting element after given key:");
    traversal(&tail);
    printf("\n");
    insertbefore(&tail,90,50);    
    printf("the circularlinkedlist after inserting element before given key:");
    traversal(&tail);
    printf("\n");
}
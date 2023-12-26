#include<stdio.h>
#include<stdlib.h>
#include"doublyLL.h"

int init(struct nodeLL **head,struct nodeLL **tail){
    *head=*tail=NULL;
    return 0;
}
int insertatposition(struct nodeLL **head,struct nodeLL **tail,int datatoinsert ,int pos){
    if(pos<0){
        return 0;//incorrect position
    }
    struct nodeLL*newnode=(struct nodeLL*)malloc(sizeof(struct nodeLL));
    if(newnode==NULL){
        return 0; 
    }
    newnode->data=datatoinsert;
    if(*head==NULL){
        //empty list case
        if(pos==1){//inserting the 1st element to empty list
            newnode->next=newnode->prev=NULL;
            *head=*tail=newnode;
        }
        return 1;
    }
    else{//non empty list case
        int i=1;
        struct nodeLL*iter=*head;
        while(i<pos-1 && iter!=NULL){
            iter=iter->next;
            i++;
        }
        if(iter==NULL){//the pos is not present as it is already out of loop 
            return 0;
        }
        else{//if i=pos-1.......iter is at just before pos nodeLL
    
            if(pos==1){//inserting at begining
                newnode->next=*head;
                (*head)->prev=newnode;
                newnode->prev=NULL;
                *head=newnode;
                return 1;
            }
            if(i==pos-1){
                if(iter->next!=NULL){//inserting at middle.............<-^->||||->^<-
                    newnode->next=iter->next;
                    newnode->prev=iter;
                    iter->next=newnode;
                    (newnode->next)->prev=newnode;
                    return 1;
                }
                else{//inserting at endd
                    newnode->next=iter->next;//its null here if we want to specify
                    newnode->prev=iter;
                    iter->next=newnode;
                    *tail=newnode;
                    return 1;
                }
            }
        }
    }
}
int deletebyelement(struct nodeLL **head,struct nodeLL **tail,int datatodelete){
    struct nodeLL*ptr1=*head;
    while(ptr1!=NULL && ptr1->data!=datatodelete){
        ptr1=ptr1->next;
    }
    if(ptr1==NULL){//empty list case or data not found in entire list
        return 0;
    }
    if(ptr1->data==datatodelete){
        if(ptr1==*head && ptr1==*tail){//deleting only nodeLL case
            *head=*tail=NULL;
        }
        else if(ptr1==*head){//delete at start so head changing
            *head=(*head)->next;
            (*head)->prev=NULL;
        }
        else if(ptr1!=*tail){//delete in middle
            (ptr1->prev)->next=ptr1->next;
            (ptr1->next)->prev=ptr1->prev;
        }
        else{//delete at end so tail changing
            *tail=(*tail)->prev;
            (*tail)->next=NULL;
        }
        free(ptr1);
        return 1;
    }
}

int search(struct nodeLL **head,struct nodeLL **tail,int datatofind){
    struct nodeLL*ptr2=*head;
    while(ptr2!=NULL && ptr2->data!=datatofind){
        ptr2=ptr2->next;
    }
    if(ptr2==NULL){//empty list case or data not found in entire list
        printf("no data found\n");
        return 0;
    }
    if(ptr2->data==datatofind){
        printf("data found\n");
        return 1;
    }
}
int traverseforward(struct nodeLL **head){
    // if(*head=NULL){
    //     printf("the DLL is empty");
    //     return 0;
    // }
    struct nodeLL*ptr3=*head;
    while(ptr3!=NULL){
        printf("%d->",ptr3->data);
        ptr3=ptr3->next;
    }
    printf("NULL\n");
    return 1;
}
int traversebackward(struct nodeLL**tail){
    // if(*tail=NULL){
    //     printf("the DLL is empty");
    //     retrn 0;
    struct nodeLL*ptr4=*tail;
    while(ptr4!=NULL){
        printf("%d<-",ptr4->data);
        ptr4=ptr4->prev;
    }
    printf("NULL\n");
    return 1;
}
int finding_small_large(struct nodeLL **head,struct nodeLL **tail,int *smallp,int *largep){
    if(*head==NULL){
		printf("list is empty\n");
		return 0;
	}
	int small=(*head)->data;
	int large=(*head)->data;
	struct nodeLL *dupli=*head;
	while(dupli!=NULL){
		if(small>(dupli->data)){
			small=dupli->data;
		}
		if(large<(dupli->data)){
			large=dupli->data;
		}
		dupli=dupli->next;
	}
	*smallp=small;
	*largep=large;
	return 1;
}



#include<stdio.h>
#include<stdlib.h>

//here givig idea to cpu how a node(like a unit of linkedlists(no of nodes connected ))
struct node{
    int data;//it is a data part of node in linkedlist its like 1 part of box(2 parts) 
    struct node*next;//here"next" is pointervariable pointing to address of next node data
};// or we can use typedef so we no need to use struct everytime we use node

//struct node*head;//declaring head pointer which used to point to node that we req
//initialization of head pointer 
//simply pointing the head pinter to null...here it is empty list (we can say)

int init(struct node **head){
    *head=NULL;//its set to null
    printf("initializing linkedlist\n");
    return 1;
}

int insert(struct node **head,int pos,int data){
    //creating a new node 
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("out of memory\n");
        //here we can remove that to free memory
        return 0;
    }
    newnode->data=data;//(*newnode).data=data
    //it means giving data to datapart of newnode
    //insertion at 1st position of linkedlist
    if(pos==1){
        newnode->next=*head;//here linking the address of node(previous head node) to newnode
        *head=newnode;
        return 1;
    }
    struct node*pre=*head;
    for( int i=1; pre->next!=NULL && i<pos-1 ;i=i+1){
        pre=pre->next;
    }
    if(!pre){
        //here pre =null if pos is out of last node also like not at end too more than that 
        //or pos<1 is given so 
        return 0;
    }
    else{
        newnode->next=pre->next;
        pre->next=newnode;
        return 1;
    }
}

int insertafter(struct node **head,int predata,int data){
    //creating a new node 
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("out of memory\n");
        return 0;
    }
    newnode->data=data;//(*newnode).data=data
    //it means giving data to datapart of newnode
    //insertion at 1st position of linkedlist
    struct node*pre=*head;
    for( int i=1; pre->next!=NULL && pre->data!=predata ;i=i+1){
        pre=pre->next;
    }
    if(!pre){
        //here pre =null if pos is out of last node also like not at end too more than that 
        //or pos<1 is given so 
        printf("no data here\n");
        return 0;
    }
    if(pre->data==predata){
        newnode->next=pre->next;
        pre->next=newnode;
        return 1;
    }
} 
int insertbefore(struct node **head,int postdata,int data){
    //creating a new node 
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("out of memory\n");
        return 0;
    }
    newnode->data=data;//(*newnode).data=data
    //it means giving data to datapart of newnode
    //insertion at 1st position of linkedlist
    if((*head)->data==postdata){
        newnode->next=*head;//here linking the address of node(previous head node) to newnode
        *head=newnode;
        return 1;
    }
    struct node*pre=*head;
    for( int i=1;pre->next!=NULL && (pre->next)->data!=postdata;i=i+1){
        pre=pre->next;
    }
    if(!(pre->next)){
        //here pre =null if pos is out of last node also like not at end too more than that 
        //or pos<1 is given so 
        return 0;
    }
    else{
        newnode->next=pre->next;
        pre->next=newnode;
        return 1;
    }
} 
int search(struct node **head,int key,struct node **ptrToKey){
    struct node*pre=*head;
    for( int i=1;pre->next!=NULL && pre->data!=key;i=i+1){
        pre=pre->next;
    }
    if(!(pre->next)){
        //here pre =null if pos is out of last node also like not at end too more than that 
        //or pos<1 is given so 
        printf("data is not found\n");
        *ptrToKey=NULL;
        return 0;
    }
    else{
        *ptrToKey=pre;
        printf("\nsearchingitem is found at %d and it is %d\n",pre,pre->data);
        return 1;
    }
}
int traverse(struct node **head){
    struct node*ptr;
    for(ptr=*head;ptr;ptr=ptr->next){
        printf("%d ",ptr->data);
    }
    printf("NULL\n");
    return 1;
}

//deletes the data from the list
int deleteItem(struct node **head, int datac){
    struct node*current=*head;//here it traverse through untill it reaches desired data it stops if reaches     
    struct node*pre=NULL;//it will be one step back of current
    while(current && current->data!=datac){
        //here current shouldnot be null and data must not equal to datac to enter loop
        pre=current;
        current=current->next;
    }
    //ifLL is empty from start or no data found case too
    if(!current){
         return 0;
    }
    //if 1st node data itself matches then it wont enter loop right so....
    if(!pre){
        *head=(*head)->next;//yeah it will point to null but do
        free(current);//now it will become empty LL
        return 1;
    }
    //loop end coz item matched somewhere middle or end of LL 
    else{
        pre->next=current->next;
        free(current);//deleting node that have matched data
        return 1;
    }

 }

//deletes the node at the position pos and returns the data deleted in *data
int deleteByPosition(struct node **head, int pos, int *dataf){
    //empty case here or given pos doesnot exist
    struct node*current=*head;
    struct node*pre=NULL;
    if(pos<1||!(*head)){
        *dataf=NULL;
        return 0;
    }
    if(pos==1){
        *dataf=current->data;
        free(current);
        return 1;
    }
    for(int i=1;i<pos && current!=NULL;i++){
        pre=current;
        current=current->next;
    }
    if(!current){
        *dataf=NULL;
        return 0;
    }
    else{
        *dataf=current->data;
        pre->next=current->next;
        free(current);
        return 1;
    }
}
//destroys the list
int destroy(struct node** head){
    struct node*ptr=*head;
    while(*head){
        *head=(*head)->next;
        free(ptr);
        ptr=*head;
    }
    return 1;
}

int main(){
    int data;
    struct node*head;//declaration of head pointer to use
    struct node*ptrTokey=NULL;
    init(&head);
    insert(&head,1,10);
    insert(&head,2,20);
    insert(&head,3,30);
    traverse(&head);
    insertafter(&head,40,60);
    traverse(&head);
    insertafter(&head,30,60);
    traverse(&head);
    insertbefore(&head,30,70);
    traverse(&head);
    search(&head,20,&ptrTokey);
    deleteItem(&head,30);
    traverse(&head);
    deleteByPosition(&head,2,&data);
    traverse(&head);
    destroy(&head);
    traverse(&head);
    return 0;
}

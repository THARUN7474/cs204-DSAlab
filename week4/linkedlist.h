struct node{
    int data;//it is a data part of node in linkedlist its like 1 part of box(2 parts) 
    struct node*next;//here next is pointervariable pointing to address of next node data
};

int init(struct node **head);
//👆👆 => initializes the head pointer
int insert(struct node **head,int pos,int data);
//👆👆 => inserts data at the position specified
int insertafter(struct node **head,int predata,int data);
//👆👆=> inserts data immediately after the node containing preData
int insertbefore(struct node **head,int postData,int data); 
//👆👆=> inserts data immediately before the node containing postData
int search(struct node **head,int key, struct node **ptrToKey);
//👆👆=> searches for the key in the list and returns a pointer to the key (if found) in ptrToKey.
int traverse(struct node **head);
//👆👆=> Prints the list
int deleteByPosition(struct node **head, int pos, int *data);
//👆👆deletes the node at the position pos and returns the data deleted in *data
int deleteItem(struct node **head, int data);
//👆👆deletes the data from the list
int destroy(struct node** head);
//👆👆destroys the list

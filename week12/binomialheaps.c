#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *parent,*sib,*child;
    int deg;
};
struct Node* root=NULL;
int binomiallink(struct Node *h1,struct Node *h2){
    h1->parent=h2;
    h1->sib=h2->child;
    h2->child=h1;
    h2->deg=(h2->deg) + 1;
}

struct Node *create(int n){
    struct Node* newnode;
    newnode=(struct Node*)(malloc(sizeof(struct Node)));
    newnode->data=n;
    newnode->parent=NULL;
    newnode->sib=NULL;
    newnode->child=NULL;
    newnode->deg=0;
    return newnode;
}

struct Node *merge(struct Node *h1,struct Node *h2){
    if(h1==NULL){
        return h2;
    } else if(h2==NULL){
        return h1;
    }
    struct Node *p;
    if((h1->deg)>(h2->deg)){
        p=h2;
    } else if((h1->deg)<=(h2->deg)){
        p=h1;
    }
    while(h1!=NULL && h2!=NULL){
        if((h1->deg)<(h2->deg)){
            h1=h1->sib;
        } else if((h1->deg)==(h2->deg)){
            struct Node *k=h1->sib;
            h1->sib=h2;
            h1=k;
        } else {
            struct Node *k=h2->sib;
            h2->sib=h1;
            h2=k;
        }
    }
    return p;
}

struct Node *unionheap(struct Node *h1, struct Node *h2) {
    if (h1 == NULL && h2 == NULL) {
        return NULL;
    }
    struct Node *p = merge(h1, h2);
    struct Node *prev = NULL;
    struct Node *curr = p;
    struct Node *next = p->sib;
    while (next != NULL) {
        if ((curr->deg) != (next->deg) || (next->sib != NULL && (next->sib)->deg == (curr->deg))) {
            prev = curr;
            curr = next;
        } else {
            if ((curr->data) < (next->data)) {
                curr->sib = next->sib;
                binomiallink(next,curr);
            } else {
                if (prev == NULL) {
                    p = next;
                } else {
                    prev->sib = next;
                }
                binomiallink(curr,next);
                curr = next;
            }
        }
        next = curr->sib;
    }
    return p;
}

struct Node *findnode(struct Node *h,int val){
    if(h==NULL){
        return NULL;
    }
    if(h->data == val){
        return h;
    }
    struct Node *p;
    p=findnode(h->child,val);
    if(p!=NULL){
        return p;
    }
    return findnode(h->sib,val);
}

void decreasekey(struct Node *h,int old,int new){
    struct Node *p;
    p=findnode(h,old);
    if(p==NULL){
        printf("not possible");
    }
    p->data=new;
    struct Node *par=p->parent;
    while(par!=NULL && p->data < par->data){
        int k=p->data;
        p->data=par->data;
        par->data=k;
        p=par;
        par=par->parent;
    }
}

struct Node* extractMin(struct Node *h) {
    if (h== NULL) {
        printf("Heap is empty\n");
        return NULL;
    }
    struct Node* minNode = h;
    struct Node* prev = NULL;
    struct Node* prevMin = NULL;
    struct Node* curr = minNode->sib;
    while (curr) {
        if (curr->data < minNode->data) {
            minNode = curr;
            prevMin = prev;
        }
        prev = curr;
        curr = curr->sib;
    }
    if (prevMin){
        prevMin->sib = minNode->sib;
    } else{
        h = minNode->sib;
    }
    struct Node* minChild = minNode->child;
    while (minChild) {
        struct Node* next = minChild->sib;
        minChild->sib = NULL;
        h=unionheap(h, minChild);
        minChild = next;
    }
    return minNode;
}

void insert(int n){
    root=unionheap(root,create(n));
}

void display(struct Node *root){
    while(root){
        printf("%d->",root->data);
        display(root->child);
        root=root->sib;
    }
}
int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display(root);
    extractMin(root);
    printf("\n");
    display(root);
    return 0;
}
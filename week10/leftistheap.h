#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left,*right;
	int npl;
};

struct node* merge(struct node* h1,struct node* h2);
struct node* mergeR(struct node* hmax,struct node* hmin);
struct node* insertM(struct node** H,int* A);
struct node* extractMax(struct node* H,int* data);
struct node* mergeK(struct node** arr);
int traversal(struct node* H);
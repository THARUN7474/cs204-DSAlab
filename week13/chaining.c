#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.c"
#define m 7


int inserthash(struct node*  arr[],int i,int n){
	int k=i%n;
	insert(&arr[k],1,i);
	return 0;
}

int traversehash(struct node* arr[],int n){
	for(int i=0;i<n;i++){
		traverse(&arr[i]);
        // printf("\t");
	}
}

int search1(struct node* arr[],int n,int i){
	int k=i%n;
	struct node * temp=arr[k];
	while(temp && temp->data!=i){
		temp=temp->next;
	}
	if(!temp){
		return 0;
	}
	if(temp->data==i){
		return 1;
	}
}

int deletehash(struct node *arr[],int n,int i){
	int k=i%n;
	deleteItem(&(arr[k]),i);
	return 0;
}
	
int main(){
	struct node* arr[m];
	for(int i=0;i<m;i++){
		arr[i]=NULL;
	}
	inserthash(arr,8,m);
	inserthash(arr,5,m);
	inserthash(arr,7,m);
    inserthash(arr,11,m);
    inserthash(arr,14,m);
	traversehash(arr,m);
    printf("\n");
	int u=search1(arr,m,97);
	printf("%d if IT IS '0' THEN KEY IS not found else it is found\n",u);
	deletehash(arr,m,5);
	traversehash(arr,m);
	return 0;
}
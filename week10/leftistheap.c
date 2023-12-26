#include"leftistheap.h"

struct node* merge(struct node* h1,struct node* h2){
	if(!h1){
		return h2;
	}
	if(!h2){
		return h1;
	}
	if(h1->key >= h2->key){
		return mergeR(h1,h2);
	}else{
		return mergeR(h2,h1);
	}
}

struct node* mergeR(struct node* hmax,struct node* hmin){
	struct node *temp;
	if(!(hmax->left)){
		hmax->left=hmin;
	}else{
	hmax->right=merge(hmax->right,hmin);
	if(hmax->npl < hmax->right->npl){
		temp=hmax->right;
		hmax->right=hmax->left;
		hmax->left=temp;
	}
	hmax->npl=(hmax->right->npl)+1;
	}
	return hmax;
}
struct node* insertM(struct node** H,int A[]){
	int n=sizeof(A);
	int i=0;
	struct node* temp;
	while(i<=n && A[i]!=NULL){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->key=A[i];
		temp->left=NULL;
		temp->right=NULL;
		temp->npl=0;
		*H=merge(*H,temp);
		i++;
	}
	//free(temp);
	return *H;
}

struct node* extractMax(struct node* H,int* data){
	if(!H){
		return H;
	}
	*data=H->key;
	return merge(H->right,H->left);
}

struct node* mergeK(struct node** arr){
	if(!arr){
		return NULL;
	}
	int i=0;
	while(arr[i]!=NULL){
		return merge(arr[i],arr[i+1]);
		i=i+2;
	}
}

int traversal(struct node* H){
	if(H){	
		traversal(H->left);
		traversal(H->right);
		printf("%d->",H->key);
	}
	//else{
	//	printf("\nNULL");
	//}
	return 1;
}
#include"leftistheap.h"

int main(){
	int data;
	struct node *H,*T,*V,*F;
	H=NULL;
	T=NULL;
	V=NULL;
	F=NULL;
	int a[5]={10,6,5,8,1};
	int b[5]={3,5,9,1,2};
	int c[5]={6,9,3,20,10};
	printf("starting\n");
	insertM(&H,a);
	insertM(&T,b);
	insertM(&V,c);
	printf("insertion completed\n");
	traversal(H);
	printf("\n");
	traversal(T);
	printf("\n");
	traversal(V);
	extractMax(H,&data);
	printf("\n%d\n",data);
	extractMax(T,&data);
	printf("\n%d\n",data);
	extractMax(V,&data);
	printf("\n%d\n",data);
	printf("traversal completed\n");
	struct node* arr[3]={H,T,V};
	F=mergeK(arr);
	traversal(F);
	return 1;
}
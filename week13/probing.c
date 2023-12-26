#include<stdio.h>
#include<stdlib.h>
#define m 7

struct new{
	int data;
	int flag;
};

int hashfind(int i,int n,int u){
	int k=(i+u)%n;
	return k;
}

int inserthash(struct new arr[],int n,int i){
	int u=0;
	if(arr[hashfind(i,n,u)].data==0){
		arr[hashfind(i,n,u)].data=i;
		return 1;
	}
	else{
		while(arr[hashfind(i,n,u)].data!=0 || arr[hashfind(i,n,u)].flag!=0){
			u=u+1;
			if(u>n){
				printf("\nelement cant be inserted\n");
				return 0;
			}
		}
		arr[hashfind(i,n,u)].data=i;
		return 0;
	}
}

int search1(struct new arr[],int n,int i){
	int u=0;
	if(arr[hashfind(i,n,u)].data==i){
		printf("\nelement found\n");
		return 1;
	}
	else{
		while(arr[hashfind(i,n,u)].data!=0 || arr[hashfind(i,n,u)].flag!=0){
			u=u+1;
			if(u>n){
				printf("\nelement not found\n");
				return 0;
			}
		}
		
		if(arr[hashfind(i,n,u)].data==i){
		printf("\nelement found\n");
		}
		else{
		printf("\nelement not found\n");
		}
		return 1;
	}

	}
int deletehash(struct new arr[],int n,int i){
	int u=0;
	if(arr[hashfind(i,n,u)].data==i){
		arr[hashfind(i,n,u)].data=0;
		arr[hashfind(i,n,u)].flag=1;
		return 1;
	}
	else{
		while(arr[hashfind(i,n,u)].data!=i || arr[hashfind(i,n,u)].flag==1){
			if(arr[hashfind(i,n,u)].data==i){
				break;
			}
			u=u+1;
			if(u>n){
				printf("element not found\n");
				return 0;
			}
		}
		if(arr[hashfind(i,n,u)].data==i){
			arr[hashfind(i,n,u)].data=0;
			arr[hashfind(i,n,u)].flag=1;
		}
		else{
			printf("element not found\n");
		}
		return 1;
	}
}
int main(){
	struct new arr[m];
	for(int i=0;i<m;i++){
		arr[i].data=0;
		arr[i].flag=0;
	}
	inserthash(arr,m,1);
	inserthash(arr,m,2);
	inserthash(arr,m,3);
    inserthash(arr,m,14);
	inserthash(arr,m,8);
	inserthash(arr,m,8);
	inserthash(arr,m,8);
	inserthash(arr,m,8);
	for(int i=0;i<m;i++){
		printf("%d\t",arr[i].data);
	}	
	search1(arr,m,3);
	search1(arr,m,9);
	deletehash(arr,m,2);
	deletehash(arr,m,2);
	for(int i=0;i<m;i++){
		printf("%d\t",arr[i].data);
	}
	return 0;
}
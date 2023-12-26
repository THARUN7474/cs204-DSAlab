#define SIZE 100
#include<stdio.h>
#include<stdbool.h>

//this will search for item and if there it gives position of it in array

bool search(int arr[SIZE],int item,int *pos,int len){
    if(len==0){
        printf("array is empty");
        *pos=-1;
        return false;
    }
    int i=0;
    while(i<len && arr[i]!=item){
        i=i+1;//why not for-loop can be used??check again
    }
    if(i==len){//as loop ends here no further elements to search
        *pos=-1;
        printf("no item found\n");
        return false;
    }
    else{//here too loop breaked but due to item was found at i postion
        *pos=i;
        printf("item is found at postion\n");
        return true;
    }
}
int main(){
    int arr[SIZE],len,pos,item;
    printf("enter the length of array u want:");
    scanf("%d",&len);
    printf("give the elements to be in list:");
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter a item to search :");
    scanf("%d",&item);
    search(arr,item,&pos,len);
    printf("the req item is at postion:%d\n",pos);
    return 0;
}
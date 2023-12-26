#define SIZE 100
#include<stdio.h>
#include<stdbool.h>

bool display(int arr[SIZE],int len){
    if(len==0){
        printf("list is empty");
        return false;
    }
    if(len<0||len>SIZE){
        printf("asked list legnth is more than defined size");
        return false;
    }
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n\n");
    return true;
}

bool deletebyitem(int arr[SIZE],int len,int item,int *pos){
    if(len==0){
        *pos=-1;
        return false;
    }
    for(int i=0;i<len;i++){
        if(arr[i]==item){
            *pos=i;
            for(int j=i;j<len;j++){
                arr[j]=arr[j+1];
            }
        }
    }
    len--;
    return true;
}

int main(){
    int arr[SIZE],len,pos,item;
    printf("enter the length of array u want:");
    scanf("%d",&len);
    printf("give the elements to be in list:");
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter a item to delete by item method :");
    scanf("%d",&item);
    deletebyitem(arr,len,item,&pos);
    printf("the item deleted is at postion:%d\n",pos);
    len=len-1;
    display(arr,len);
    return 0;
}
#define SIZE 100
#include<stdio.h>
#include<stdbool.h>
bool display(int arr[SIZE],int len){
    if(len==0){
        printf("list is empty\n");
        return false;
    }
    if(len<0||len>SIZE){
        printf("asked list legnth is more than defined size\n");
        return false;
    }
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n\n");
    return true;
}

bool oddevensort(int arr[SIZE],int len){
    if(len==0){
        return false;
    }
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-2;j++){
            if((j%2==0 && arr[j]<arr[j+2]) || (j%2!=0 && arr[j]>arr[j+2])){
                int t=arr[j];
                arr[j]=arr[j+2];
                arr[j+2]=t;
            }
        }
    }return true;
}

int main(){
    int arr[SIZE],len,pos,item;
    printf("enter the length of array u want:");
    scanf("%d",&len);
    printf("give the elements to be in list:");
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    oddevensort(arr,len);
    display(arr,len);
    return 0;
}
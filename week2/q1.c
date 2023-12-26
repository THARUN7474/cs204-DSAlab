#define SIZE 100
#include<stdio.h>
#include<stdbool.h>

//to display elements of an array ----------->display funtion

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
    return true;
}

int main(){
    int arr[SIZE],len;
    printf("enter the length of array u want");
    scanf("%d",&len);
    printf("give the elements to be in list");
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    display(arr,len);
    return 0;
}
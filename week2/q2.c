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

//insert by postion ......the item is inserted at given position as pos

bool insertbypostiion(int arr[SIZE],int item,int pos,int *len){
    if(*len>=SIZE){
        printf("len of given list is morethan max size of list\t");
        printf("array is full cannot insert\n");
        return false;
    }
    if(pos<0||pos>=*len){
        printf("the req postion is not avaliable for inserting(out of size of list)\n");
        return false;
    }
    for(int i=*len-1;i>=pos;i--){
        arr[i+1]=arr[i];
        /*eachtime elements shifting untill the element space at position pos will be empty
        for inserting the req item at that position pos*/
    }
    arr[pos]=item;
    *len+=1;//for increasing len of list as new item inserted use pointers
    //check again later
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
    printf("enter the item to be insert:");
    scanf("%d",&item);
    printf("enter at which position as pos:");
    scanf("%d",&pos);
    insertbypostiion(arr,item,pos,&len);
    display(arr,len);
    return 0;
}
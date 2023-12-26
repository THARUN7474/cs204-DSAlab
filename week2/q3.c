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

//delete by postion and the item is deleted is printed 

bool deletebypostion(int arr[SIZE],int pos,int *item,int *len){
    if(*len<=0){
        printf("len of given list is out of range of list\t");
        printf("array is empty");
        return false;
    }
    if(pos<0||pos>*len){
        printf("the req postion is not avaliable for deleting item(out of size of list\n)");
        return false;
    }
    *item=arr[pos];//for retreving deleting item use pointers here
    //check again pontiers and address related
    for(int i=pos;i<*len-1;i++){
        arr[i]=arr[i+1];
        /*eachtime elements shifting untill the element space at position(pos) is occupied
        for deleting the item at the asked position pos*/
    }
    *len-=1;//for decreasing len of list as a item deleted use pointers
    //check again later//or keep this in main fun after fun call
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
    printf("enter at which position to delete :");
    scanf("%d",&pos);
    deletebypostion(arr,pos,&item,&len);
    printf("the item deleted %d\n",item);
    display(arr,len);
    return 0;
}
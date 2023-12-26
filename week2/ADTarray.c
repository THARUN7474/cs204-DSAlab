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

//insert by postion ......the item is inserted at given position as pos

bool insertbypostiion(int arr[SIZE],int item,int pos,int *len){
    if(*len>=SIZE){
        printf("len of given list is morethan max size of list\t");
        printf("array is full cannot insert\n");
        return false;
    }
    if(pos<0||pos>*len){
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
    for(int i=pos;i<(*len)-1;i++){
        arr[i]=arr[i+1];
        /*eachtime elements shifting untill the element space at position(pos) is occupied
        for deleting the item at the asked position pos*/
    }
    *len-=1;//for decreasing len of list as a item deleted use pointers
    //check again later//or keep this in main fun after fun call
    return true;
}

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

//this is for deleting item by giving item and getting at which pos it is deleted ....by this len gets drop by 1

bool deletebyitem(int arr[SIZE],int *len,int item,int *pos){
    if(*len==0){
        *pos=-1;
        return false;
    }
    for(int i=0;i<*len;i++){
        if(arr[i]==item){
            *pos=i;//geting position of item as pos using pointer
            for(int j=i;j<*len;j++){
                arr[j]=arr[j+1];
            }
            *len-=1;
        }
        else{
            int *pos=NULL;
        }
    }
   
    return true;
}

int main(){
    int arr[SIZE],len,pos,item,item1,item2;
    printf("enter the length of array u want:");
    scanf("%d",&len);
    printf("give the elements to be in list:");
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the item to be insert:");
    scanf("%d",&item1);
    printf("enter at which position as pos:");
    scanf("%d",&pos);
    insertbypostiion(arr,item1,pos,&len);
    display(arr,len);//here len increses by one ---updated len

    printf("enter at which position to delete :");
    scanf("%d",&pos);
    deletebypostion(arr,pos,&item,&len);
    printf("the item deleted %d\n",item);
    display(arr,len); // here updated len agian updates by decreasing one due to delebypos function call

    printf("enter a item to search :");
    scanf("%d",&item2);
    search(arr,item2,&pos,len);
    printf("the req item is at postion:%d\n",pos);//here no change in list(array)so no need of display fun

    printf("enter a item to delete by item method :");
    scanf("%d",&item);
    deletebyitem(arr,&len,item,&pos);
    printf("the item deleted is at postion:%d\n",pos);
    display(arr,len);

    return 0;
}



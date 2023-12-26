#include<stdio.h>
#define MAX 100

int matchingpair(int arr[MAX],int len,int matchingnumber){
    for(int i=0;i<len;i++){
        int sum=0;
        for(int j=i+1;j<len;j++){
            sum=arr[i]+arr[j];
            if(sum==matchingnumber){
                printf("the matched pair of numbers are %d and %d",arr[i],arr[j]);
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int arr[MAX],len,sumM;
    printf("enter the number that to match as sum:");
    scanf("%d",&sumM);
    printf("enter the length of array u want:");
    scanf("%d",&len);
    printf("give the elements to be in list in increasing order only:");
    for(int i=0;i<len;i++){
        scanf("%d",&arr[i]);
    }
    matchingpair(arr,len,sumM);
    return 0;
}
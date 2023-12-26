#include<stdio.h>

#define SIZE 100
#include<stdio.h>
#include<stdbool.h>

int main() {
    int a=2,b=3;
    printf("%d,%d",a,b);
    return 0;

}
int arr[100]={1,2,4,3,5,6,7};
    int insertingitem=8;
    int len=7;
    int pos=2;
    for(int i=0;i<len;i=i+2){
            m=arr[0];
            if(arr[i+2]>m){
                m=arr[i+2];
            }
        }
        for(int i=1;i<len;i=i+2){
            n=arr[1];
            if(arr[i+2]>n){
                m=arr[i+2];
            }
        }

int m,n;
    int i=0;
    m=arr[0];
    while(i<=len){
        i=i+2;
        if(arr[i+2]>m){
            m=arr[i+2];
        }
    }
    int j=1;
    n=arr[1];
    while(j<=len){
        j=j+2;
        if(arr[j+2]>n){
            n=arr[j+2];
        }
    }
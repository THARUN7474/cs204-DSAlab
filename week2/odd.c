#include<stdio.h>
#include<stdbool.h>
bool oddeven(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-2;j++){
            if((j%2==0 && a[j]<a[j+2]) || (j%2!=0 && a[j]>a[j+2])){
                int temp=a[j];
                a[j]=a[j+2];
                a[j+2]=temp;
            }
        }
    }return true;
}
int main(){
    int a[10]={1,2,3,4,5};
    oddeven(a,5);
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }return 0;
}
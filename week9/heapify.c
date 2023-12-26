#include<stdio.h>

// here heapsize will be no of nodes(n)...last node count and in array representation it is last element
// height(0-1-2-3) and nodes be like(1-2-3-4).....height of heap(cbt) is h=log(n) 
int swap(int a,int b){
    int t=a;
    a=b;
    b=t;
    return 1;
}
int minheapify(int arr[],int N,int i){
    // N is heapsize
    int varptr=i; 
    int l=2*i;//left node of node---arr[i]
    int m=(2*i)+1;//right node  of node----arr[i]
    if(l<=N && arr[varptr]>arr[l]){
        varptr=l; }
    if(m<=N && arr[varptr]>arr[m]){
        varptr=m;}
    if(varptr!=i){
        //swap(arr[varptr],arr[i]);
        int t=arr[varptr]; 
        arr[varptr]=arr[i];
        arr[i]=t; 
        minheapify(arr,N,varptr);
    }
    return 1;
}
//floor of N/2 give parent node of a given node......ex 5 node parent node is 2 
int construct_heapify(int arr[], int N){
    for(int i=(N/2);i>=1;i--){
        minheapify(arr,N,i);
    }
    // for(int j=N,j>=1,j--){
    //     swap(arr[1],arr[j])
    //     minheapify(arr,N,1)
    // }
    return 1;
}
int main(){
    int arr[10];
    int N;
    printf("enter N value");
    scanf("%d", &N);
    printf("enter elements in order with gap(space)"); 
    for(int i=1;i<N+1;i++) {
        scanf("%d",&arr[i]);} 
    for(int j=1;j<=N;j++){ 
        printf("%d->",arr[j]);
    }
    printf("\n");
    construct_heapify(arr,N);
    for(int j=1;j<=N;j++){ 
        printf("%d->",arr[j]);
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int minheapify(int *H,int hs,int i){
    int varptr=i; 
    int l=2*i;
    int m=(2*i)+1;
    if(l<=hs && H[varptr]>H[l]){
        varptr=l; }
    if(m<=hs && H[varptr]>H[m]){
        varptr=m;}
    if(varptr!=i){
        int t=H[varptr]; 
        H[varptr]=H[i];
        H[i]=t; //swap(H[varptr],H[i]);
        minheapify(H,hs,varptr);
    }
    return 1;
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int construct_heapify(int *H, int hs){
    for(int i=(hs/2);i>=1;i--){
        minheapify(H,hs,i);
    }
    return 1;
}
int findMin(int *H, int hs, int *min) {
    if(hs==0){
        return 0;
    }
    *min=H[1];
    return 1;
}
int extractMin(int *H, int hs, int *min) {
    if(hs==0){
        return 0;
    }
    *min=H[1];
    H[1]=H[hs];
    hs=hs-1;
    minheapify(H,hs,1);
    return 1;
}

int decreaseKey(int* H, int hs, int i, int newvalue){
    int dupli;
    if(i>hs || i<1){
        return 0;
    }
    if(H[i]<=newvalue){
        return 0;
    }
    H[i]=newvalue;
    while(i>1 && H[i]<H[i/2]){
        dupli=H[i];
        H[i]=H[1/2];
        H[i/2]=dupli;
        i=i/2;
    }
    return 1;
}
int insertkey(int *H,int *hs,int value){
    if(*hs==0){
        return 0;
    }
    *hs=*hs+1;
    H[*hs]=value;
    printf("%d\n",*hs);
    for(int j=1;j<=*hs;j++){ 
        printf("%d->",H[j]);
    }
    printf("\n");
    construct_heapify(H,*hs);
    return 1;
}

int combineHeaps(int *H1, int *H2,int hs1,int hs2, int *F){ 
    if(hs1==0){
        return 0;
    }
    int min;
    int z=1;
    int i=1;
    int j=1;
    while(i<=hs1 || j<=hs2){
        if(H1[i]<H2[j]){
            min=H1[1];
            F[z]=min;
            z++;
            i++;
        }else{
            min=H2[j];
            F[z]=min;
            j++;
            z++;
        }
    }
    return 1;
}
int combinearr_heaps(int *CH,int size){
    if(size==0){
        return 0;
    }
    construct_heapify(CH,size);
    return 1;
}
int heapsort(int *H,int hs){
    int i;
    for(i=(hs/2);i>=1;i--){
        minheapify(H,hs,i);
    }
    for(int j=hs;j>=1;j--){
        //swap(H[1],H[j])
        int t;
        t=H[i];
        H[i]=H[j];
        H[j]=t;
        minheapify(H,hs,1);
    }
    return 1;
}

int main(){
    int H1[100];
    int H2[100];
    int F[100];
    int CB[100];
    int hs1;
    printf("enter hs1 value");
    scanf("%d", &hs1);
    printf("enter elements in order with gap(space)"); 
    for(int i=1;i<hs1+1;i++) {
        scanf("%d",&H1[i]);} 
    printf("\n the 1st array H1[]:\n");
    for(int j=1;j<=hs1;j++){ 
        printf("%d->",H1[j]);
    }
    printf("\n");

    int hs2;
    printf("enter hs2 value");
    scanf("%d", &hs2);
    printf("enter elements in order with gap(space)"); 
    for(int i=1;i<hs2+1;i++) {
        scanf("%d",&H2[i]);} 
    printf("\n the 2nd array H2[]:\n");
    for(int j=1;j<=hs2;j++){ 
        printf("%d->",H2[j]);
    }
    printf("\n");

    for(int c=1;c<hs1+1;c++){
        CB[c]=H1[c];   
    }
    for(int d=1;d<hs2+1;d++){
        CB[d+hs1]=H2[d];   
    }
    printf("\nthe new combine array thats need to be minheap\n");
    for(int e=1;e<(hs1+hs2)+1;e++){
        printf("%d->",CB[e]);
    }
    printf("\n");

    construct_heapify(H1,hs1);
    printf("\n the 1st array H1[] after becoming minheap:\n");
    for(int j=1;j<=hs1;j++){ 
        printf("%d->",H1[j]);
    }
    printf("\n");

    int min;
    findMin(H1,hs1,&min);
    printf("%d= the min in heap\n",min);

    int min1;
    extractMin(H1,hs1,&min1);
    printf("%d= the min1 in heap\n",min1);
    for(int j=1;j<=hs1;j++){ 
        printf("%d->",H1[j]);
    }
    printf("\n");

    decreaseKey(H1,hs1,5,4);
    for(int j=1;j<=hs1;j++){ 
        printf("%d->",H1[j]);
    }
    printf("\n");

    insertkey(H1,&hs1,5);
    for(int j=1;j<=hs1;j++){ 
        printf("%d->",H1[j]);
    }
    printf("\n");

    heapsort(H1,hs1);
    for(int j=1;j<=hs1;j++){ 
        printf("%d->",H1[j]);
    }
    printf("\n");

    construct_heapify(H2,hs2);
    printf("\n the 2nd array H2[] after becoming minheap:\n");
    for(int j=1;j<=hs2;j++){ 
        printf("%d->",H2[j]);
    }
    printf("\n");

    combineHeaps(H1,H2,hs1,hs2,F);
    printf("\n the combine array H1 and h2[]after minheaping:\n");
    for(int k=1;k<=(hs1+hs2);k++){ 
        printf("%d->",F[k]);
    }
    printf("\n");

    combinearr_heaps(CB,hs1+hs2);
    for(int f=1;f<=(hs1+hs2);f++){ 
        printf("%d->",CB[f]);
    }
    printf("\n");
    return 0;
}
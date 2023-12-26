#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define n 10

struct stack{
    int arr[MAXSIZE];
    int top;

};
int init(struct stack *s){
    s->top=-1;
    return 1;
}
int destroy(struct stack *s){
    s->top=-1;
    return 1;
}
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack *s,int data){
    if(MAXSIZE<=(s->top)){
        return 0;
    }
    s->arr[(s->top)+1]=data;
    (s->top)++;
    return 1;
}
int pop(struct stack *s,int *data){
    if(s->top==-1){
        return 0;
    }

    *data=s->arr[s->top];
    (s->top)--;
    return 1;
}
int isSafe(int b[n][n],int r,int c){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]){
                if(i==r){
                    return 0;
                }
                if(j==c){
                    return 0;
                }
                if(i-j==r-c || i+j==r+c){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int NQUEENS(){
    //int n=N;
    int b[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=0;
        }
    }
    int r=0;int c=0;
    struct stack p1;
    struct stack p2;
    init(&p2);
    init(&p1);
    while(r<n){
        c=0;
        while(c<n){
            if(isSafe(b,r,c)){
                b[r][c]=1;
                push(&p1,r);
                push(&p2,c);
                break;
            }
            else{
                c=c+1;
            }
            while(c>=n){
                if(isEmpty(&p1)){
                    return 0;//this will be impossible case
                }
                pop(&p1,&r);
                pop(&p2,&c);
                b[r][c]=0;
                c=c+1;
                }
        }
        r++;
    }
    for(int a=0;a<n;a++){
        for(int m=0;m<n;m++){
            printf("%d\t",b[a][m]);
        }
        printf("\n");
    }
    destroy(&p1);
    destroy(&p2);
    return 1;
}

int main(){
    //int n=10;
    // int b[n][n];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         b[i][j]=0;
    //     }
    // }
    //printf("%d/n",n)
    NQUEENS();
    return 0;
}
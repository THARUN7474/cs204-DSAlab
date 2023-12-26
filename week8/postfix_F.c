#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000

struct stack{
    int arr[SIZE];
    int top;
};

int init(struct stack *s){
    s->top=-1;
    printf("\nnew stack ARR formed\n");
    return 1;
}
int destroy(struct stack *s){
    s->top=-1;// here arr gets empty ...as top is one set to -1 means no elements
    printf("stack ARR is destroyed\n");
    return 1;
}
int isEmpty(struct stack *s){
    if(s->top==-1){
        printf("stack ARR is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *s){
    if(s->top==SIZE-1){
        printf("stack ARR is full\n");
        return 1;}
    else{
        return 0;}
}
int push(struct stack *s,int datain){
    if((isFull(s))){
        printf("cant push as it is already full\n");
        return 0;
    }
    (s->top)++;
    s->arr[s->top]=datain;
    return 1;
}
int pop(struct stack *s,int *dataout){
    if((isEmpty(s))){
        printf("cant pop as it is already empty\n");
        return 0;
    }
    *dataout=s->arr[s->top];
    (s->top)--;
    return 1;
}

int peek(struct stack *s,int *dataout){
    if((isEmpty(s))){
        printf("cant peek as it is already empty\n");
        return 0;
    }
    *dataout=s->arr[s->top];
    return 1;
}

int apply( int op1, int op2,char op){
    switch(op){
        case '+':
           return(op1+op2);
           printf("%d\n",op1+op2);
           break;
        case '-':
           return(op1-op2);
           printf("%d\n",op1-op2);
           break;
        case '*':
           return(op1*op2);
           printf("%d\n",op1*op2);
           break;
        case '/':
           return(op1/op2);
           printf("%d\n",op1/op2);
           break;
        default:
           break;
    }
    printf("invalid operator used");
    return NULL;
}

int evaluatepostfix(char *postfix,int *value){
    int op1=0,op2=0;
    int val;
    int valu;
    struct stack S;
    init(&S);
    while (*postfix!='\0'){
        //if(*postfix>'\0'&& *postfix<='9'){
        if(*postfix=='0'||*postfix=='1'||*postfix=='2'||*postfix=='3'||*postfix=='4'||*postfix=='5'||*postfix=='6'||*postfix=='7'||*postfix=='8'||*postfix=='9'){
            push(&S,*postfix);
        }
        else{
            if(isEmpty(&S)){
                return 0;
            }
            pop(&S,&op2);//her it will be  NUMBER EX 2 means (50)(ascii)so coverting into normal int
            //actually  as pop is int return type so the '2' forcly covert into its ascii int value (50)
            //so we manually again covert it into normal by -'0'ascii value(48)
            printf("%d\n",op2-48);
            if(isEmpty(&S)){
                return 0;
            }
            pop(&S,&op1);
            printf("%d\n",op1-48);
            val=apply(op1-48,op2-48,*postfix);
            //her the val is itself pure int type so we need to covert it as ascii type so we add 48 so automatically it get
            printf("%d\n",val+48);
            push(&S,val+48);
        }
        *postfix++;
    }
    if(!(isEmpty(&S))){
        pop(&S,&valu);
        *value=(valu)-48;
        printf("%d\n",*value);
        destroy(&S);
        return 1;
    }
    else{
        destroy(&S);
        return 0;
    }
}
int main(){
    printf("hello");
    // struct stack Sa;
    // init(&Sa);
    int answer;
    char str[SIZE];
    printf("enter the postfix expression ex->'52+3*'<-:");
    scanf("%s",str);
    printf("\n%s",str);
    evaluatepostfix(str,&answer);
    printf("the evaluted value of given postfix exp is->->%d",answer);
    return 0;
}
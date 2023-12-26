#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct stack{
    int arr[SIZE];
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
int isFull(struct stack *s){
    if(s->top=SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack *s,char data){
    if(SIZE<=(s->top)){
        return 0;
    }
    s->arr[(s->top)+1]=data;
    (s->top)++;
    return 1;
}
int pop(struct stack *s,char *data){
    if(s->top==-1){
        return 0;
    }

    *data=s->arr[s->top];
    (s->top)--;
    return 1;
}
int peek(struct stack *s,char *data){
    if(s->top==-1){
        return 0;
    }

    *data=s->arr[s->top];
    return 1;
}
int priority(char c){
    if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
int infixtopostfix(char *infix,char postfix[]){
    int i=0;
    char c;
    struct stack sobj;
    init(&sobj);
    while(*infix!='\0'){
        if(*infix>='0' && *infix<='9'){
            postfix[i++]=*infix;
        }
        else if(*infix=='('){
            push(&sobj,'(');
        }
        else if(*infix==')'){
            pop(&sobj,&c);
            while(!isEmpty(&sobj) && c!='('){
                postfix[i++]=c;
                pop(&sobj,&c);
            }
        }
        else{
            peek(&sobj,&c);
            while(!isEmpty(&sobj) && priority(*infix)<=priority(c)){
                pop(&sobj,&c);
                postfix[i++]=c;
                peek(&sobj,&c);
            }
            push(&sobj,*infix);
        }
        infix++;
    }
    while(!isEmpty(&sobj)){
        pop(&sobj,&c);
        postfix[i++]=c;
    }
    postfix[i++]='\0';
    puts(postfix);
    destroy(&sobj);
    return 1;
}
int main(){
    //char *infix="(5+2)*3";
    int answer;
    char str[SIZE];
    printf("enter the postfix expression ex->'52+3*'<-:");
    scanf("%s",str);
    printf("\n%s",str);
    char postfix[100]={'0'};
    infixtopostfix(&str,postfix);
}

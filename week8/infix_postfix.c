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
int infixTopostfix(struct stack* f,struct stack* d){
	char datap='0';
	char symbol='0';
	while(!isEmpty(f)){
		pop(f,&datap);
		if(datap=='0'||datap=='1'||datap=='2'||datap=='3'||datap=='4'||datap=='5'||datap=='6'||datap=='7'||datap=='8'||datap=='9'){
			push(d,datap);
			continue;
		}
		if(symbol!='0'){
				push(d,symbol);
			}
		symbol=datap;
		continue;
		
	}
	push(d,symbol);
	return 1;
}
int main(){
	struct stack s;
	init(&s);
	push(&s,'5');
	push(&s,'+');
	push(&s,'3');
	struct stack d;	
	init(&d);
	infixTopostfix(&s,&d);
	char o;
	peek(&d,&o);
	return 1;
}
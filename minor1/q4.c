#include<stdio.h>
#include<stdlib.h>
struct stack{
	struct node* top;
};
struct node{
	char data;
	struct node *next;
};
int init(struct stack *s){
	s->top=NULL;
}
int push(struct stack *s,char data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=s->top;
	s->top=newnode;
	return 1;
}
int popvowel(struct stack *s){
	struct node *dupli=s->top;
	while(dupli!=NULL){//this is for if s->top->data is vowel......last of stack is vowel case
		char c=s->top->data;
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
			s->top=s->top->next;
			dupli=s->top;
			continue;
		}
        else{
            dupli=NULL;
        }
	}
	dupli=s->top;
	while(dupli->next!=NULL){
		char c=dupli->next->data;
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
			dupli->next=dupli->next->next;
		}
		else{
			dupli=dupli->next;
		}
	}
	return 1;
}
int main(){
	struct stack s;
	init(&s);
	printf("enter the stack like stirng but last char please enter '0'.....example='hi0' :\n");
	char c='1';
	while(c!='0'){
		scanf("%c",&c);
		if(c!='0'){
		push(&s,c);}
	}
    printf("after  removing vowels\n");
	popvowel(&s);
	struct node *dupli=(&s)->top;
	while(dupli!=NULL){
		printf("%c\t",dupli->data);
		dupli=dupli->next;
	}
	return 0;
}
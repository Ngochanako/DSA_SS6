#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char data[100];
	int top;
} Stack;

//khoi tao ngan xep
void initiliaze(Stack* stack){
	stack->top=-1;
}
//kiem tra ngan xep day
bool isFull(Stack* stack){
	return stack->top==99;
}
//kiem tra ngan xep rong
bool isEmpty(Stack* stack){
	return stack->top==-1;
}
//them phan tu vao ngan xep
void push(Stack* stack, int n){
	if(isFull(stack)){
		return;
	}
	stack->data[++stack->top]=n;
}
//lay phan tu tren cung stack
char top(Stack* stack){
	return stack->data[stack->top];
}
//in ra phan tu stack 
void printStack(Stack* stack){
	for(int i=stack->top;i>=0;i--){
		printf("%c",stack->data[i]);
	}
}
//xoa phan tu tren cung ngan xep
void pop(Stack* stack){
	stack->top--;
}
//kiem tra tinh hop le cua bieu thuc
bool check(Stack* stack,char s[]){
	int l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]=='['||s[i]=='{'||s[i]=='('){
			push(stack,s[i]);
		}else if(!isEmpty(stack)){
			if((top(stack)=='('&&s[i]==')')||(top(stack)=='['&&s[i]==']')||(top(stack)=='{'&&s[i]=='}')){
				pop(stack);
			}
		}
	}
	return isEmpty(stack);
}
int main(){
	char str[100];
	fgets(str,sizeof(str),stdin);
	int l=strlen(str);
	Stack stack;
	initiliaze(&stack);
	if(check(&stack,str)){
		printf("Bieu thuc hop le");
	}else{
		printf("Bieu thuc khong hop le");
	}
    
}

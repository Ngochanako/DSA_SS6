#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
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
    int mid=strlen(s)/2;
    int j=mid;
    if(strlen(s)%2==1){
    	j=mid+1;
	}
	for(int i=0;i<mid;i++){
		push(stack,s[i]);
	}
	for(int i=j;i<strlen(s);i++){
		if(s[i]!=top(stack)){
			
			return false;
		}
		pop(stack);
	}
	return true;
}
int main(){
	char str[100];
	gets(str);
	int j=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]!=' '){
			str[j++]=tolower(str[i]);
		}
	}
	str[j]='\0';
	Stack stack;
	initiliaze(&stack);
	if(check(&stack,str)){
		printf("Chuoi doi xung");
	}else{
		printf("Chuoi khong doi xung");
	}  
}

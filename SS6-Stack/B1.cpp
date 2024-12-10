#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data[100];
	int top;
} Stack;

//khoi tao ngan xep

void initializeStack(Stack* stack){
	stack->top=-1;
}
//ham kiem tra ngan xep co day khong
bool isFull(Stack* stack){
	return stack->top==99;
}
//ham kiem tra ngan xep co rong khong
bool isEmpty(Stack* stack){
	return stack->top==-1;
}
//ham them phan tu vao ngan xep
void push(Stack* stack,int n){
	if(isFull(stack)){
		printf("Ngan xep da day");
		return;
	}
	stack->data[++stack->top]=n;
}
//ham xoa phan tu tren cung cua ngan xep
void pop(Stack* stack){
	if(isEmpty(stack)){
		printf("Ngan xep da rong");
		return;
	}
	stack->top--;
}
//in cac phan tu ngan xep tu phan tu tren cung
void printStack(Stack* stack){
	for(int i=stack->top;i>=0;i--){
		printf("%d ",stack->data[i]);
	}
}

int main(){
	int n,x;
	scanf("%d",&n);
	Stack stack;
	initializeStack(&stack);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		push(&stack,x);
	}
	printStack(&stack);
}

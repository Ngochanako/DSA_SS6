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
void push(Stack* stack, char n){
	if(isFull(stack)){
		return;
	}
	stack->data[++stack->top]=n;
}
//xoa phan tu tren cung va in ra phan tu do
int pop(Stack* stack){
	if(isEmpty(stack)){
		return -1;
	}
	return stack->data[stack->top--];
}
//in ra phan tu stack 
void printStack(Stack* stack){
	for(int i=stack->top;i>=0;i--){
		printf("%d ",stack->data[i]);
	}
}
//in ra phan tu tren cung
char top(Stack* stack){
	return stack->data[stack->top];
}
//kiem tra bieu thuc hop le
bool check(Stack* stack,char s[]){
	for(int i=0;i<strlen(s);i++){
		if(s[i]!=')'&&s[i]!='}'&&s[i]!=']'){
			push(stack,s[i]);
		}else if(isEmpty(stack)){
			return false;
		}else if(top(stack)=='('||top(stack)=='['||top(stack)=='{'){
			return false;
		} else{
			bool check=false;
			while(top(stack)!='('&&top(stack)!='['&&top(stack)!='{'&&!isEmpty(stack)){
				if(top(stack)=='+'||top(stack)=='-'||top(stack)=='*'||top(stack)=='/'){
					check=true;
				}
				pop(stack);
			}
			if(!check){
				return false;
			}
			if(isEmpty(stack)){
			return false;
		    }
			if(top(stack)=='('&&s[i]==')'||top(stack)=='{'&&s[i]=='}'||top(stack)=='['&&s[i]==']'){
				pop(stack);
			}else{
			    return false;
			}
		}
	}
	while(!isEmpty(stack)){
		if(top(stack)=='('||top(stack)=='['||top(stack)=='{'){
			return false;
		}
		pop(stack);
	}
	return true;
}
//ham them ky tu vao cuoi chuoi
void insertToTail(char** str,int* size,char c){
		(*size)++;
		*str=(char*)realloc(*str,(*size+1)*sizeof(char));
		(*str)[(*size)-1]=c;
		(*str)[(*size)]='\0';
}
//ham chuyen infix to postfix
void convert(Stack* stack,char s[]){
	int l=strlen(s);
	char* str=NULL;
	int size=0;
	for(int i=0;i<l;i++){
		if(s[i]=='('){
			push(stack,s[i]);
		}else if(s[i]==')'){
			while(top(stack)!='('){
			   	insertToTail(&str,&size,top(stack));
				pop(stack);	
			}
			pop(stack);
		} else if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'){
			insertToTail(&str,&size,s[i]);
		}else if(s[i]=='+'||s[i]=='-'){
			if(!isEmpty(stack)&&top(stack)!='('){
				insertToTail(&str,&size,top(stack));
				pop(stack);
				push(stack,s[i]);
			}else{
				push(stack,s[i]);
			}
			
		}else{	
		    if(isEmpty(stack)){
		    	push(stack,s[i]);
			}else if(top(stack)=='('){
				push(stack,s[i]);
			}
			else{
				if(top(stack)=='+'||top(stack)=='-'){
				push(stack,s[i]);
				}else{
				insertToTail(&str,&size,top(stack));
				pop(stack);
				push(stack,s[i]);	
				}
			}		
		}
	}
	while(!isEmpty(stack)){
		insertToTail(&str,&size,top(stack));
		pop(stack);
	}
	printf("%s",str);
	free(str);
}
int main(){
	char s[100];
	gets(s);
	Stack stack;
	initiliaze(&stack);
    if(!check(&stack,s)){
    	printf("Bieu thuc khong hop le");
	}else{
		convert(&stack,s);
	}
}

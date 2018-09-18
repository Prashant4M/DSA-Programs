#include<stdio.h>
#define SIZE 10
void push(int);
int pop();
void Display();
int isEmptyStack(int);
int isFullStack(int);
int stack[SIZE],top=-1,i,value,n;
void main()
{

	printf("We can enter 10 elements in the Stack.\n");
	for(i=1;i<=10;i++)
	{
		printf("Enter the element in the stack:");
		scanf("%d",&value);
		push(value);
	}
	printf("Stack is Created.\n");
	Display();
	n=pop();
	printf("\nPopped Data:%d\n");
	Display();
}
void push(int data)
{
	if(isFullStack(top))
	{
		printf("Stack overflow!!\n");
	}
	stack[++top]=data;
}
int isFullStack(int i)
{
	return i==SIZE-1;
}
int pop()
{
	int poppedData;
	if(isEmptyStack(top))
	{
		printf("\nStack underflow!!");
	}
	poppedData=stack[top];
	top--;
	return poppedData;
}
int isEmptyStack(int i)
{
	return i==-1;
}
void Display()
{
	if(isEmptyStack(top))
	{
		printf("\nStack is empty!!");
		return;
	}
	for(i=top;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}


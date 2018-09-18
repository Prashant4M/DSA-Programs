#include<stdio.h>
#define SIZE 10
void push_stack1(int);
void push_stack2(int);
int pop_stack1();
int pop_stack2();
void Display_stack1();
void Display_stack2();
int stack[SIZE],top1=-1,i,j,value,n,top2=SIZE;
void main()
{

	printf("We can enter 10 elements in the Stack.\n");
	for(i=1;i<=6;i++)
	{
		printf("Enter the element in the stack 1:");
		scanf("%d",&value);
		push_stack1(value);
	}
	printf("Stack 1 is Created.\n");
	for(i=1;i<=4;i++)
	{
		printf("Enter the element in the stack 2:");
		scanf("%d",&value);
		push_stack2(value);
	}
	printf("Stack 2 is Created.\n");
	printf("1st stack is:");
	Display_stack1();
	printf("\n");
	printf("2nd stack is:");
	Display_stack2();
	printf("\n");
	push_stack2(12);
	n=SIZE-top2;
	while(n--)
	{
		j=pop_stack2();
		printf("%d is being popped from stack 2.\n",j);
	}
	Display_stack2();
	pop_stack2();
}
void push_stack1(int data)
{
	if(top1<top2-1)
	{
		stack[++top1]=data;
	}
	else
	{
		printf("Stack 1 Full Can't push!!\n");
	}
}
void push_stack2(int data)
{
	if(top1<top2-1)
	{
		stack[--top2]=data;
	}
	else
	{
		printf("Stack 2 Full Can't push!!\n");
	}
}
int pop_stack1()
{
	int poppedData;
	if(top1==-1)
	{
		printf("\nStack underflow!!");
		return;
	}
	poppedData=stack[top1];
	top1--;
	return poppedData;
}
int pop_stack2()
{
	int poppedData;
	if(top2==SIZE)
	{
		printf("\nStack underflow!!");
		return;
	}
	poppedData=stack[top2];
	top2++;
	return poppedData;
}
void Display_stack1()
{
	if(top1==-1)
	{
		printf("\nStack is empty!!");
		return;
	}
	for(i=top1;i>=0;i--)
	{
		printf("%d\t",stack[i]);
	}
}
void Display_stack2()
{
	if(top2==SIZE)
	{
		printf("\nStack is empty!!");
		return;
	}
	for(i=top2;i<SIZE;i++)
	{
		printf("%d\t",stack[i]);
	}
}



#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int info;
	struct stack *next;
}*top=NULL;
typedef struct stack Stack;
void push(int n)
{
	Stack *newnode=(Stack *)malloc(sizeof(Stack));
	newnode->info=n;
	if(top==NULL)
	{
		newnode->next=NULL;
	}
	else
	{
		newnode->next=top;
	}
	top=newnode;
}
void main()
{
	int n,value;
	printf("Enter the number of elements in the stack:");
	scanf("%d",&n);
	while(n--)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		if(top==NULL||top->info>=value)
		{
			push(value);
		}
		else
		{
			push(top->info);
		}
	}
	printf("\nMinimunElement in the stack::%d",top->next->info);
	
}

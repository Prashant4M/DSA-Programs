#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;

int pop(NODE **);
void display(NODE *);
void push(NODE **,int );
void main()
{
	NODE *top=NULL,*top1=NULL;
	int data,num,value;
	printf("Enter the number of Elements in the stack:");
	scanf("%d",&num);
	while(num--)
	{
		printf("Enter the value you want to enter:");
		scanf("%d",&value);
		push(&top,value);
	}
	printf("Your Original satck is:\n");
	display(top);
	while(top!=NULL)
	{
		data=pop(&top);
		push(&top1,data);
	}
	printf("\nYour reversed stack is:\n");
	display(top1);
}
void push(NODE **top,int n)
{
		NODE *newnode=(NODE *)malloc(sizeof(NODE));
		newnode->data=n;
		if(*top==NULL)
		{
			newnode->next=NULL;
		}
		else
		{
		newnode->next=*top;
		}
		*top=newnode;
}
void display(NODE *top)
{
	if(top==NULL)
	{
		printf(" Now Stack is empty!!");
	}
	else
	{
		while(top!=NULL)
		{
			printf("%d\n",top->data);
			top=top->next;
		}
	}
}
int pop(NODE **top)
{
	int i;
	if(*top==NULL)
	{
		printf("Stack is empty!");
	}
	else
	{
	NODE *temp=*top;
	*top=(*top)->next;
	i=temp->data;
	free(temp);
	}
	return i;
}

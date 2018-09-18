#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
void push(int ,NODE **);
void pop(NODE **);
void display(NODE *);
void DeleteStack(NODE **);
void main()
{
	NODE *top=NULL;
	int num,value;
	printf("Enter the number of Elements in the stack:");
	scanf("%d",&num);
	while(num--)
	{
		printf("Enter the value you want to enter:");
		scanf("%d",&value);
		push(value,&top);
	}
	printf("Your satck is:\n");
	display(top);
pop(&top);
DeleteStack(&top);
display(top);
}
void push(int n,NODE **top)
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
		printf("\nNow Stack is empty!!");
	}
	else
	{
		while(top!=NULL)
		{
			printf("%d  ",top->data);
			top=top->next;
		}
	}
}
void pop(NODE **top)
{
	if(*top==NULL)
	{
		printf("\nStack is empty!");
	}
	else
	{
	NODE *temp=*top;
	*top=(*top)->next;
	printf("\nPopped element is %d.",temp->data);
	free(temp);
	}
}
void DeleteStack(NODE **top)
{
	NODE *p=*top,*temp;
	while(p->next)
	{
		temp=p->next;
		p->next=temp->next;
		free(temp);
	}
	free(p);
	*top=NULL;
}

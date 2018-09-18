#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
}*top=NULL,*BottomNode=NULL;
typedef struct node NODE;
void push(int n)
{
	
	NODE *newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=n;
	if(top==NULL)
	{
		newnode->next=newnode;
		BottomNode=newnode;
	}
	else
	{
		newnode->next=top;
	}
	top=newnode;
	BottomNode->next=top;
}
int pop()
{
	NODE *temp;
	int data=0;
	if(top==NULL)
	{
		printf("Stack is empty!!\n");
		return;
	}
	temp =top;
	if(top == BottomNode)
	{
		data=top->data;
		free(top);
		top=NULL;
		BottomNode=NULL;
	}
	else
	{
	top = top->next;
	BottomNode->next = top;
	data=temp->data;
	free(temp);
	}
	printf("\nPopped Data::%d\n",data);
}
void Display()
{
	NODE *current=top;
    do
	{
		printf("%d\t",current->data);
		current=current->next;
	}while(current!=top);
}
int main()
{
	int n,x,value,choice;
	while(1)
	{
		printf("\n==============================================\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("==============================================\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to insert:");
	  			scanf("%d",&value);
	  			push(value);
	  			break;
	  		case 2:
	  			x=pop();
	  			break;
	  		case 3:
	  			Display();
	  			break;
	  		case 4:
	  			exit(0);
	  		default:
	  			printf("Enter a valid choice..");
	  			break;
	  	}
	}
	printf("Bottom Node is connected with topmost node.\n");
	printf("\nYour stack is::\n");
	Display();
}


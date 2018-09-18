#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;
typedef struct node Node;
struct stack
{
	Node *Queue1;
	Node *Queue2;
};
void Push(struct stack *s,int n)
{
	if(s->Queue1==NULL)
		EnQueue(s->Queue2,n);
	else
		EnQueue(s->Queue1,n);
}
int pop(struct stack *s)
{
	int i=0,size;
	if(!s->Queue1)
	{
		size=Size(s->Queue2);
		while(i<size-1)
		{
			EnQueue(s->Queue1,DeQueue(s->Queue2));
			i++;
		}
		return DeQueue(s->Queue2);
	}
	if(!s->Queue2)
	{
		size=Size(s->Queue1);
		while(i<size-1)
		{
			EnQueue(s->Queue2,DeQueue(s->Queue1));
			i++;
		}
		return DeQueue(s->Queue1);
	}
}
int Size(Node *q)
{
	int i=1;
	Node *current=front;
	while(current!=rear)
	{
		current=current->next;
		i++;
	}
	return i;
}
void EnQueue(Node *q,int n)
{
	Node *newnode=(Node *)malloc(sizeof(Node));
	newnode->data=n;
	newnode->next=NULL;
	if(front==NULL)
	    front=rear=newnode;
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
int DeQueue(Node *q)
{
	int data=0;
	if(front==NULL)
	{
		printf("Queue is Empty!!");
		return 0;
	}
	else
	{
		Node *temp=front;
		front=front->next;
		data=temp->data;
		free(temp);
	}
	return data;
}
int main()
{
	int i,num,value;
	struct stack *s=(struct stack *)malloc(sizeof(struct stack));
	s->Queue1=NULL;
	s->Queue2=NULL;
	printf("Enter the nunmber of elements to be contained in the stack::");
	scanf("%d",&num);
	i=num;
	while(i--)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		Push(s,value);
	}
	printf("Stack with %d elements is created.\n",num);
	printf("Popped Element::%d\n",pop(s));
	printf("Popped Element::%d",pop(s));
}

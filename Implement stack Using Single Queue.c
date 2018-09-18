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
	Node *Queue;
};
void Push(struct stack *s,int n)
{
	EnQueue(s->Queue,n);
}
int pop(struct stack *s)
{
	int i=0,size=Size(s->Queue);
	while(i<size-1)
	{
		EnQueue(s->Queue,DeQueue(s->Queue));
		i++;
	}
	return DeQueue(s->Queue);
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
	s->Queue=NULL;
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
}

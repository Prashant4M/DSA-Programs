/*Program to impement Queue using two stacks*/
#include<stdio.h>
#include<stdlib.h>
struct stackNODE
{
	int data;
	struct stackNODE *next;
}*top=NULL;
typedef struct stackNODE NODE; 
struct queue
{
	NODE *stack1;
	NODE *stack2;
};
typedef struct queue Queue;
void EnQueue(Queue *q,int data)
{
	push(&q->stack1,data);
}
int DeQueue(Queue *q)
{
	int x;
	if(q->stack1==NULL && q->stack2==NULL)
	{
		printf("Queue is Empty!!\n");
		exit(0);
	}
	if(q->stack2==NULL)
	{
		while(q->stack1)
		{
			x=pop(&q->stack1);
			push(&q->stack2,x);
		}
	}
	x=pop(&q->stack2);
	return x;
}
void push(NODE **top_ref,int data)
{
	NODE *newnode=(NODE *)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("Stack Overflow!!");
		exit(0);
	}
	newnode->data=data;
	newnode->next=(*top_ref);
	(*top_ref)=newnode;
}
int pop(NODE **top)
{
	int x;
	if(*top==NULL)
	{
		printf("Stack Overflow!");
	}
	NODE *temp;
	temp=*top;
	(*top)=(*top)->next;
	x=temp->data;
	free(temp);
	return x;
}
void Display(NODE *top)
{
	while(top)
	{
		printf("%d\t",top->data);
		top=top->next;
	}
}
int main()
{
	int num,value,i;
	Queue *q=(Queue *)malloc(sizeof(Queue));
	q->stack1=NULL;
	q->stack2=NULL;
	printf("Enter the nunmber of elements to be contained in the Queue::");
	scanf("%d",&num);
	i=num;
	while(i--)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		EnQueue(q,value);
	}
	printf("Queue with %d elements is created.\n",num);
	printf("\nDequeued Element:%d\n",DeQueue(q));
	printf("Dequeued Element:%d\n",DeQueue(q));
}

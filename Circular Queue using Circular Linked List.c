#include<stdio.h>
#include<stdlib.h>
struct cs{
	int data;
	struct cs *next;
};
struct cs *front= NULL,*rear=NULL;
struct cs *q = NULL;
struct cs *create()
{
	struct cs *p;
	p = (struct cs *)malloc(sizeof(struct cs));
	return p;
}
void EnQueue(int data)
{
	struct cs *temp;
	temp = create();
	temp->data = data;
	temp->next = temp;
	if(front == NULL)
	{
		front=rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
	rear->next=front;
}
void DeQueue()
{
	int data=0;
	struct cs *temp;
	if(front == NULL)
	{
		printf("Queue Is Empty :\n");
		return;
	}
    if(front==rear)
    {
    	data=front->data;
    	free(front);
    	front=NULL;
    	rear=NULL;
	}
	else
	{
		temp=front;
		front=front->next;
		rear->next=front;
		data=temp->data;
		free(temp);
	}
	printf("DeQueued Data:%d\n",data);
}
void Display()
{
	struct cs *temp;
	temp = front;
	do{
		printf("%d->",temp->data);
		temp = temp->next;
	}while(temp != front);
}
int main()
{
	int n,value;
	printf("1.EnQueue.\n");
	printf("2.DeQueue.\n3.Display.\n4.Exit\n");
	while(1)
	{
	printf("Enter your choice :\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("Enter the data of node :\n");
			scanf("%d",&value);
			EnQueue(value);
			break;
		case 2:
			DeQueue();
			break;
		case 3:
			Display();
			break;
		case 4:
			exit(0);
			break;
	}
	}
	return 0;
}

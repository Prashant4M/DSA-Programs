#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*head=NULL;
typedef struct Node NODE;
void Insert()
{
	int choice,value,locValue;
	while(1)
	{
	printf("\n*****************************************************\n");
	printf("1.At Beginning\n2.At End\n3.At any location\n4.Main Menu");
	printf("\n*****************************************************\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:{
				printf("Enter the value to insert:");
				scanf("%d",&value);
			NODE *newnode=(NODE *)malloc(sizeof(NODE));
			newnode->data=value;
			if(head==NULL)
			{
				head=newnode;
				newnode->next=head;
			}
			else
			{
				NODE *temp=head;
				while(temp->next!=head)
				{
					temp=temp->next;
				}
				newnode->next=head;
				head=newnode;
				temp->next=head;
			}
			printf("Insertion Success!!\n");
			break;
		}
		case 2:{
				printf("Enter the value to insert:");
	scanf("%d",&value);
	NODE *newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=value;
			if(head==NULL)
			{
				head=newnode;
				newnode->next=head;
			}
			else
			{
			NODE *temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->next=head;
			printf("Insertion Success!!\n");
			}
			break;
		}
		case 3:{
				printf("Enter the value to insert:");
	scanf("%d",&value);
	NODE *newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=value;
			NODE *current=head;
			printf("Enter the number after which you want the node:");
			scanf("%d",&locValue);
			if(head==NULL)
			{
				head=newnode;
				newnode->next=head;
			}
			else
			{
				while(current->data!=locValue)
				{
					if(current->next==head)
					{
						printf("Value is not present in the list!!\n");
						return;
					}
					else
					{
						current=current->next;
					}
				}
				newnode->next=current->next;
				current->next=newnode;
				printf("Insertion done!!");
			}
			break;
		case 4:
			return;
			break;
		}
	}
  }
}
void Display()
{
	NODE *current=head;
	while(current->next!=head)
	{
		printf("%d->",current->data);
		current=current->next;
	}
	printf("%d",current->data);
}
int main()
{
	int choice,value;
	while(1)
	{
	printf("\n========================================================================\n");
	printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
	printf("========================================================================\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			Insert();
			break;
		case 2:
			Display();
			break;
	}
	}
	return 0;
}

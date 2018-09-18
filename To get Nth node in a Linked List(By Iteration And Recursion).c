#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void GetNthNode(NODE *,int );
void GetNthNodeByRecursion(NODE *,int index);
void Display(NODE *);
int main()
{
	NODE *head=NULL;
	int n,value,index;
	printf("Enter the number of elements to be contained in the list:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		MakeList(&head,value);
		n--;
	}
	Display(head);
	printf("\nEnter the index of node:");
	scanf("%d",&index);
	GetNthNode(head,index);
	printf("\nBy recursion:");
	GetNthNodeByRecursion(head,index);
	return 0;
}
void MakeList(NODE **root,int n)
{
	if(*root==NULL)
	{
		*root=(NODE *)malloc(sizeof(NODE));
		(*root)->data=n;
		(*root)->next=NULL;
	}
	else
	{
		NODE *p=*root,*temp;
		temp=(NODE *)malloc(sizeof(NODE));
		while(p->next)
		{
			p=p->next;
		}
		temp->data=n;
		temp->next=NULL;
		p->next=temp;
	}
}
void GetNthNode(NODE *root,int index)
{
	int count=1;
	while(root && count!=index)
	{
		root=root->next;
		count++;
	}
	if(root==NULL)
	{
		printf("\nIndex is beyond the list size!!");
		return;
	}
	printf("Node at the given index:");
	printf("%d",root->data);
}
int counter=1;
void GetNthNodeByRecursion(NODE *root,int index)
{
	if(root!=NULL)
	{
		if(counter==index)
		{
			printf("\nNode at the given index:");
			printf("%d",root->data);
	
		}
		else
		{
			GetNthNodeByRecursion(root->next,index-1);
		}
	}
	else
	{
		printf("\nIndex is beyond the list size!!");
	}
}
void Display(NODE *root)
{
	while(root)
	{
		printf("%d\t",root->data);
		root=root->next;
	}
}

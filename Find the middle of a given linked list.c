#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void MiddleNode(NODE *);
void Display(NODE *);
int main()
{
	NODE *head=NULL;
	int n,value,index;
	printf("Enter the number of elements to be contained in tha list:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		MakeList(&head,value);
		n--;
	}
	Display(head);
	MiddleNode(head);
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
void MiddleNode(NODE *root)
{
	NODE *terminating=root,*required=root;
	while(terminating && terminating->next)
	{
		terminating=terminating->next->next;
		required=required->next;
	}
	printf("\nMiddle Most node is %d.",required->data);
}
void Display(NODE *root)
{
	while(root)
	{
		printf("%d\t",root->data);
		root=root->next;
	}
}

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node *left;
	struct Node *right;
};
typedef struct Node NODE;
NODE *NewNode(int n)
{
	NODE *p=(NODE *)malloc(sizeof(NODE));
	p->info=n;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void insert(NODE **root,int n)
{
	NODE *p=(*root),*temp;
	NODE *newnode=NewNode(n);
	if(*root==NULL)
	{
		(*root)=newnode;
		printf("Root node created.\n");
		return;
	}
	while(p)
	{
		temp=p;
		if(p->info<n)
		{
			p=p->right;
		}
		else
		{
			p=p->left;
		}
	}
	if(newnode->info<temp->info)
	{
		temp->left=newnode;
	}
	else
	{
		temp->right=newnode;
	}
	printf("Value Inserted..\n");
}
void InOrder(NODE *root)
{
	InOrder(root->left); 
	printf("%d",root->info);
	InOrder(root->right);
}
void main()
{
	NODE *head=NULL;
	int value,choice;
	while(1)
	{
	printf("****************MENU*******************\n");
	printf("1.Insertion\n2.Deletion\n3.Print Inorder Traversal of the tree\n4.Exit\n");
	printf("***************************************\n");
	scanf("%d",&choice);
	switch(choice)
	
	{
		case 1:
			printf("Enter the value to insert:");
			scanf("%d",&value);
			insert(&head,value);
			break;
		case 3:
			InOrder(head);
			break;	
	}
}
}

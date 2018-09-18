#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	int item;
	struct TreeNode *left;
	struct TreeNode *right;
}*root=NULL;
struct NODE
{
	struct TreeNode node;
	struct NODE *next;
}*top=NULL;
void push(struct NODE node)
{
	struct NODE *p;
	p->node=node;
	if(top==NULL)
	{
		p->next=NULL;
	}
	else
	{
		p->next=top;
	}
	top=p;
}
struct TreeNode pop()
typedef struct TreeNode Node;
void MakeTree(int);
void InorderTraversal(Node *);
int main()
{
	int n,value;
	printf("Enter the number of nodes to be insrted in the tree:");
	scanf("%d",&n);
	while(n--)
	{
		printf("Enter the data:");
		scanf("%d",&value);
		MakeTree(value);
	}
	InorderTraversal(root);
	return 0;
}
void MakeTree(int n)
{
	if(root==NULL)
	{
		root=(Node *)malloc(sizeof(Node));
		root->item=n;
		root->left=NULL;
		root->right=NULL;
		printf("Root Node Created.\n");
	}
	else
	{
		int choice,choice2;
		Node *newNode=(Node *)malloc(sizeof(Node));
		Node *p=root,*q;
		newNode->item=n;
		newNode->left=NULL;
		newNode->right=NULL;
		printf("Enter the position to inserted(1-Left 2-Right)::");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter choice(1-Left of left 2-Right of left):");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1:
						while(p->left)
						{
							q=p;
							p=p->left;
						}
						p->left=newNode;
						printf("Inserted.\n");
						break;
					case 2:
						while(p->left->right)
						{
							p=p->left;
						}
						q=p->left;
						q->right=newNode;
						printf("Inserted.\n");
						break;
				}
				break;
			case 2:
				printf("Enter choice(1-Right of Right 2-Left of Right):");
				scanf("%d",&choice2);
				switch(choice2)
				{
					case 1:
						while(p->right)
						{
							q=p;
							p=p->right;
						}
						p->right=newNode;
						printf("Inserted.\n");
						break;
					case 2:
						while(p->right->left)
						{
							p=p->left;
						}
						q=p->right;
						q->left=newNode;
						printf("Inserted.\n");
						break;
				}
				break;
		}	
	}
}
void InorderTraversal(Node *p)
{
	if(p)
	{
		InorderTraversal(p->left);
		printf("%d\t",p->item);
		InorderTraversal(p->right);
	}
}


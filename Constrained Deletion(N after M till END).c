#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *NewNode(int n)
{
	NODE *p=malloc(sizeof(NODE));
	p->data=n;
	p->next=NULL;
	return p;
}
void Display(NODE *root)
{
	while(root)
	{
		printf("%d\t",root->data);
		root=root->next;
	}
	printf("\n");
}
void MakeList(NODE **root,int n)
{
	NODE *temp;
	temp=NewNode(n);
	if(*root==NULL)
	{
		(*root)=temp;
	}
	else
	{
		temp->next=(*root);
		(*root)=temp;
	}
}
void ConstrainedDeletion(NODE **root,int i,int j)
{
	NODE *current=*root,*temp,*p;
	int a,b;
	while(current)
	{
		for(a=1;a<i && current;a++)
		{
			current=current->next;
		}
		if(!current)
			return;
		temp=current->next;
		for(b=1;b<=j && temp;b++)
		{
			p=temp;
			temp=temp->next;
			free(p);	
		}
		current->next=temp;
		current=temp;
	}
	printf("Operation Done..\n");
}
int main()
{
	NODE *head=NULL,*head1=NULL;
	int choice,m,n,value;
	while(1)
	{
	  printf("Enter your choice:");
	  printf("\n1.Insert\n2.Perform Alternate Deletetion of N nodes after M nodes.\n3.Display\n4.Exit\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the value to be inserted:");
	  		scanf("%d",&value);
	  		MakeList(&head,value);
			break;
	  	case 2:
	  		printf("Enter number of nodes to be contained first:");
	  		scanf("%d",&m);
	  		printf("Enter number of nodes to be deleted first:");
	  		scanf("%d",&n);
	  		ConstrainedDeletion(&head,m,n);
	  		break;
	  	case 3:
	  		Display(head);
	  		break;
	  	case 4:
	  		exit(0);
	  	default:
	  		printf("Tryitng entering a valid choice!!\n");
	  }
	}
}

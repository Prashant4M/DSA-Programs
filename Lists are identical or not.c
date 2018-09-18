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
bool areIdentical(NODE *a,NODE *b)
{
	if(a==NULL && b==NULL)
	{
		return true;
	}
	if(a!=NULL && b!=NULL)
	{
		return (a->data==b->data) && areIdentical(a->next,b->next);
	}
	return false;
}
int main()
{
	NODE *head=NULL,*head1=NULL;
	int choice,choice1,value;
	while(1)
	{
	  printf("\nEnter your choice:");
	  printf("\n1.Insert\n2.Check Identity\n3.Display\n4.Exit\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the value to be inserted:");
	  		scanf("%d",&value);
	  		printf("In List 1 or List 2:");
	  		scanf("%d",&choice1);
	  		if(choice1==1)
	  		{
	  			MakeList(&head,value);
		    }
		    else
		    {
		    	MakeList(&head1,value);
			}
			break;
	  	case 2:
	  		areIdentical(head,head1)?printf("Lists are Identical."):printf(" Lists are not Identical.");
	  		break;
	  	case 3:
	  		Display(head);
	  		break;
	  	case 4:
	  		exit(0);
	  	default:
	  		printf("Tryitng entering a valid choice!!");
	  }
	}
}

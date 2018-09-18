#include<stdio.h>
#include<stdlib.h>
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
	if(!root)
	{
		*root=temp;
	}
	else
	{
		temp->next=*root;
		*root=temp;
	}
}
void DeleteAlternateNodes(NODE **root)
{
	NODE *p=*root,*temp=p->next;
	while(p && temp)
	{
		p->next=temp->next;
		free(temp);
		p=p->next;
		temp=p->next;
	}
}
int main()
{
	NODE *head=NULL,*head1=NULL;
	int choice,value;
	while(1)
	{
	  printf("****************************************************\n");
	  printf("1.Insert\n2.Delete Alternate Nodes\n3.Display\n4.Exit\n");
	  printf("****************************************************\n");
	  printf("\nEnter your choice:");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the value:");
	  		scanf("%d",&value);
	  		MakeList(&head,value);
	  		break;
	  	case 2:
	  		DeleteAlternateNodes(&head);
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

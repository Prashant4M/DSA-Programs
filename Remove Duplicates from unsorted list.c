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
void RemoveDuplicates(NODE **root)
{
	NODE *p,*q,*temp;
	for(p=*root;p!=NULL;p=p->next)
	{
		temp=NULL;
		for(q=p->next;q!=NULL && (p->data!=q->data);q=q->next)
		{
			temp=q;
		}
		temp->next=q->next;
	}
}
int main()
{
	NODE *head=NULL;
	int choice,value;
	while(1)
	{
	  printf("\nEnter your choice:");
	  printf("\n1.Insert\n2.Remove Duplicates\n3.Display\n4.Exit\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the value:");
	  		scanf("%d",&value);
	  		MakeList(&head,value);
	  		break;
	  	case 2:
	  		RemoveDuplicates(&head);
	  		printf("Duplicates has been deleted!!");
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

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
	temp->next=(*root);
	(*root)=temp;
}
void Sort(NODE **root)
{
	NODE *p,*q;
	int temp=0;
	for(p=*root;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}
void RemoveDuplicates(NODE *root)
{
	NODE *current=root,*next;
	while(current->next!=NULL)
	{
		if(current->data==current->next->data)
		{
			next=current->next->next;
			free(current->next);
			current->next=next;
		}
		else
		{
			current=current->next;
		}
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
	  		RemoveDuplicates(head);
	  		printf("Duplicates has been deleted!!");
	  		break;
	  	case 3:
	  		Sort(&head);
	  		Display(head);
	  		break;
	  	case 4:
	  		exit(0);
	  	default:
	  		printf("Tryitng entering a valid choice!!");
	  }
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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
void AlternatingSpilt(NODE *source,NODE **aRef,NODE **bRef)
{
	NODE *current=source,*a=NULL,*b=NULL;
	while(current)
	{
		MoveNode(&a,&current);
		if(current!=NULL)
		{
			MoveNode(&b,&current);
		}
	}
	*aRef=a;
	*bRef=b;
}
void MoveNode(NODE **destRef,NODE **sourceRef)
{
	NODE *p=*destRef;
	while(p->next)
	{
		p=p->next;
	}
	p->next=(*sourceRef);
	NODE *newNode=*sourceRef;
	*sourceRef=newNode->next;
}
int main()
{
	NODE *head=NULL,*a=NULL,*b=NULL;
	int choice,value;
	while(1)
	{
	  printf("****************************************************\n");
	  printf("1.Insert\n2.Alternating Spilt of given linked list\n3.Display\n4.Exit\n");
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
	  		AlternatingSpilt(head,&a,&b);
	  		printf("After Spilting Given List is:\n");
	  		Display(a);
	  		printf("\n");
	  		Display(b);
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

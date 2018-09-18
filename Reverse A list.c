#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void CountTheOccurence(NODE **);
void Display(NODE *);
int n,value;
int main()
{
	NODE *head=NULL;

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
	ReverseTheList(&head);
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
void ReverseTheList(NODE **root)
{
	NODE *current=*root,*next,*temp=NULL;
	while(current)
	{
		next=current->next;
		current->next=temp;
		temp=current;
		current=next;
	}
	*root=temp;
	printf("\nReversed list is:\n");
	Display(*root);
}
void Display(NODE *head)
{
	NODE *current=head;
	if(current==NULL)
	{
		printf("\nList is Empty!!");
		return;
	}
	while(current)
	{
		printf("%d\t",current->data);
		current=current->next;
	}
}


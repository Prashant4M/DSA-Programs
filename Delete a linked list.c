#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void DeleteTheList(NODE **);
void Display(NODE *);
int n,value,position,count=0;
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
	
	DeleteTheList(&head);
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
void DeleteTheList(NODE **root)
{
	NODE *temp=*root,*p;
	while(temp)
	{
	   p=temp->next;
	   free(temp);
	   temp=p;
	}
 *root=NULL;
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


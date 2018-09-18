#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void GetNthFromEnd(NODE *);
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
	
	GetNthFromEnd(head);
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
void GetNthFromEnd(NODE *root)
{
NODE *aux_ptr=root,*main_ptr=root;
printf("\nEnter the position from end to look for the element:");
scanf("%d",&position);
while(count<position)
{
	aux_ptr=aux_ptr->next;
	count++;
}
while(aux_ptr!=NULL)
{
	main_ptr=main_ptr->next;
	aux_ptr=aux_ptr->next;
}
printf("\nRequired Element is:%d",main_ptr->data);
}
void Display(NODE *head)
{
	NODE *current=head;
	while(current)
	{
		printf("%d\t",current->data);
		current=current->next;
	}
}

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void CountTheOccurence(NODE *,int );
void Display(NODE *);
int n,value,num,count=0;
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
	printf("\nEnter the number to find its occurence:");
	scanf("%d",&num);
	CountTheOccurence(head,num);
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
void CountTheOccurence(NODE *root,int n)
{
	while(root)
	{
		if(root->data==n)
		{
			count++;
		}
		root=root->next;
	}
	if(count!=0)
	{
		printf("%d occurs %d times.",n,count);
	}
	else
	{
		printf("Number is not present in the list!!");
	}
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


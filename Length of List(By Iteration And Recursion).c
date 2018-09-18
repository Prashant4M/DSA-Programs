#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void LengthByRecursion(NODE *,int );
void LengthByIteration(NODE *);
int count=0;
int main()
{
	NODE *head=NULL;
	int n,value;
	printf("Enter the number of elements to be contained in tha list:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		MakeList(&head,value);
		n--;
	}

	LengthByIteration(head);
	LengthByRecursion(head,0);
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
void LengthByIteration(NODE *root)
{
	NODE *p=root;
	while(p)
   {
	    count++;
		p=p->next;
	}
	 printf("Length of the list is %d.",count);
}

void LengthByRecursion(NODE *root,int count)
{
	if(root)
	{
		count++;
		LengthByRecursion(root->next,count);
	}
	else
	{
		printf("Length of List:%d",count);
	}
}

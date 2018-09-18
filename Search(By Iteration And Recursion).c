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
void SearchByRecursion(NODE *,int );
void SearchByIteration(NODE * ,int );
int i=1,j=1;
int main()
{
	NODE *head=NULL;
	int n,value,num;
	printf("Enter the number of elements to be contained in tha list:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		MakeList(&head,value);
		n--;
	}
	printf("Enter the value to be searched:");
	scanf("%d",&num);
	printf("By Iteration:\n");
	SearchByIteration(head,num);
	printf("By Recursion:\n");
	SearchByRecursion(head,num);

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
void SearchByIteration(NODE *head,int num)
{
	NODE *p=head;
	while(p)
	{
		if(p->data==num)
		{
			printf("%d is present at position %d.\n",num,i);
			return;
		}
		i++;
		p=p->next;
	}
	printf("Element is not present in the list!\n");
}
void SearchByRecursion(NODE *root,int num)
{
	if(root)
	{
  		if(root->data==num)
   		{
   		 	printf("%d is Present at position %d\n",num,j);
    		return;
		}
		else
		{
			j++;
			SearchByRecursion(root->next,num);
		}
	}
	else
	{
		printf("Element is not present in the list!");
	}
}
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void SwapTwoNodes(NODE **,int ,int );
void Display(NODE *);
int main()
{
	NODE *head=NULL;
	int n,value,a,b;
	printf("Enter the number of elements to be contained in tha list:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		MakeList(&head,value);
		n--;
	}
	printf("List before swapping the nodes:\n");
    Display(head);
    printf("\nEnter the key values of the nodes to be swapped:\n");
    printf("Enter the first key:");
    scanf("%d",&a);
    printf("Enter the second key:");
    scanf("%d",&b);
    SwapTwoNodes(&head,a,b);
    printf("List After swapping the nodes:\n");
    Display(head);
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
void SwapTwoNodes(NODE **root,int a,int b)
{
	if(a==b)
		return;
	NODE *prevA=NULL,*prevB=NULL,*currentA=*root,*currentB=*root;
	while(currentA && currentA->data!=a)
	{
		prevA=currentA;
		currentA=currentA->next;
	}
	while(currentB && currentB->data!=b)
	{
		prevB=currentB;
		currentB=currentB->next;
	}
	if(prevA!=NULL)
		prevA->next=currentB;
	else
	{
	 *root=currentB;
	}
	if(prevB!=NULL)
		prevB->next=currentA;
	else
	{
	 *root=currentA;
	}
	 NODE *temp=currentA->next;
	 currentA->next=currentB->next;
	 currentB->next=temp;
}
void Display(NODE *root)
{
	while(root)
	{
		printf("%d\t",root->data);
		root=root->next;
	}
}

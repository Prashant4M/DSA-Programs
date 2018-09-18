#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
NODE *SortedMerge(NODE *,NODE *);
void MoveNode(NODE **,NODE **);
void Display(NODE *);
int n1,n2,value;
int main()
{
	NODE *a=NULL,*b=NULL,*result=NULL;

	printf("Enter the number of elements to be contained in the list:");
	scanf("%d",&n1);
	printf("Enter the number of elements in second list:");
	scanf("%d",&n2);
	printf("Enter data in the first list:\n");
	while(n1>0)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		MakeList(&a,value);
		n1--;
	}
	printf("\nEnter data in second list:\n");
	while(n2--)
	{
		printf("Enter the value:");
		scanf("%d",&value);
		MakeList(&b,value);
	}
	printf("First List:\n");
	Display(a);
	printf("\nSecond List:\n");
	Display(b);
	result=SortedMerge(a,b);
	printf("\nSorted List is:\n");
	Display(result);
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
NODE *SortedMerge(NODE *first,NODE *second)
{
	NODE dummy;
	NODE *res=&dummy;
	dummy.next=NULL;
	while(1)
	{
		if(first==NULL)
		{
			res->next=second;
			break;
		}
		if(second==NULL)
		{
			res->next=first;
			break;
		}
		if(first->data<=second->data)
		{
			MoveNode(&(res->next),&first);
		}
		else
		{
			MoveNode(&(res->next),&second);
		}
		res=res->next;
	}
		return(dummy.next);
}
void MoveNode(NODE **destList,NODE **sourceList)
{
	NODE *newNode=*sourceList;
	if(newNode!=NULL)
	{
		*sourceList=newNode->next;
		newNode->next=*destList;
		*destList=newNode;
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


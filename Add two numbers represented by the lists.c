#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
int MakeNumberAndSum(NODE *,NODE *);
int ReverseTheNumber(int);
void Display(NODE *);
int n,value,n2,Sum,Reverse,rev;
int main()
{
	NODE *a=NULL,*b=NULL,*result=NULL;
	printf("Enter the number of digits of first number:");
	scanf("%d",&n);
	while(n>0)
	{
		printf("Enter digit:");
		scanf("%d",&value);
		MakeList(&a,value);
		n--;
	}
	
	printf("\nEnter the number of digits in second list:");
	scanf("%d",&n2);
	while(n2--)
	{
		printf("Enter digit:");
		scanf("%d",&value);
		MakeList(&b,value);
	}
	printf("First List:\n");
	Display(a);
	printf("\nSecond List:\n");
	Display(b);
	Reverse=MakeNumberAndSum(a,b);
	rev=ReverseTheNumber(Reverse);
	while(rev>0)
	{
		MakeList(&result,rev%10);
		rev/=10;
	}
	printf("\nOur resultant List is:\n");
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
int MakeNumberAndSum(NODE *a,NODE *b)
{
   int num1=0,number1,number2;
	while(a)
	{
		num1=num1*10+(a->data);
		a=a->next;
	}
	number1=ReverseTheNumber(num1);
	num1=0;
	while(b)
	{
		num1=num1*10+(b->data);
		b=b->next;
	}
	number2=ReverseTheNumber(num1);
	return(number1+number2);
}
int ReverseTheNumber(int n)
{
	int rev=0;
	while(n>0)
	{
		rev=rev*10+(n%10);
		n/=10;
	}
	return(rev);
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


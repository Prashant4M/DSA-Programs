#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
void MakeList(NODE **,int n);
void DetectTheLoop(NODE *);
void BreakTheLoop(NODE **head,NODE **p,NODE **q);
void Display(NODE *);
int n,value,length=1;
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
    NODE *start=head,*start1=head;
    while(start->next)
    {
    	start=start->next;
	}
	start->next=start1->next->next->next;
	DetectTheLoop(head);
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
void DetectTheLoop(NODE *root)
{
	int loopexist=0,choice;
	NODE *tortoise=root,*hare=root;
	while(tortoise && hare && hare->next)
	{
		hare=hare->next->next;
		tortoise=tortoise->next;
		if(hare==tortoise)
		{
			printf("\nThere is a loop in the list..");
			loopexist=1;
			break;
		}
	}
	if(loopexist)
	{
		tortoise=root;
		while(hare!=tortoise)
		{
			hare=hare->next;
			tortoise=tortoise->next;
		}
		printf("\nLoop is starting from %d.",tortoise->data);
	}
	else
	{
		printf("\nThere exist no loop!!");
		return;
	}
	NODE *startingNode=tortoise->next;
	while(startingNode!=tortoise)
	{
		startingNode=startingNode->next;
		length++;
    }
    NODE *temp,*p=tortoise->next;
	printf("\nLength of the Loop::%d",length);
	printf("\nDo you want to break the loop(1-Yes/2-No)::");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			while(p!=tortoise)
			{
				temp=p;
				p=p->next;
			}
			temp->next=NULL;
			printf("\nLoop has been deleted.");
			DetectTheLoop(root);
			break;
		case 2:
			printf("Loop remains.");
			exit(0);
		default:
			printf("Try again with entering a valid choice!!");
			break;
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


#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *NewNode(int n)
{
	NODE *p=malloc(sizeof(NODE));
	p->data=n;
	p->next=NULL;
	return p;
}
void Display(NODE *root)
{
	while(root)
	{
		printf("%d\t",root->data);
		root=root->next;
	}
}
void MakeList(NODE **root,int n)
{
	NODE *temp;
	temp=NewNode(n);
	if(!root)
	{
		*root=temp;
	}
	else
	{
		temp->next=*root;
		*root=temp;
	}
}
void Reverse(NODE **root)
{
	NODE *temp=NULL,*nextnode,*current=*root;
	while(current)
	{
		nextnode=current->next;
		current->next=temp;
		temp=current;
		current=nextnode;
	}
	*root=temp;
}
void CheckPalindrome(NODE *root,NODE *root1)
{
	while(root && root1)
	{
		if(root->data!=root1->data)
		{
			printf("List is not Palindrome!!");
			return;
		}
		root=root->next;
		root1=root1->next;
	}
	printf("List Is Palindrome..");
}
int main()
{
	NODE *head=NULL,*head1=NULL;
	int choice,value;
	while(1)
	{
	  printf("\nEnter your choice:");
	  printf("\n1.Insert\n2.Check Palindrome\n3.Display\n4.Exit\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the value:");
	  		scanf("%d",&value);
	  		MakeList(&head,value);
	  		break;
	  	case 2:
	  		head1=head;
	  		Reverse(&head);
	  		CheckPalindrome(head,head1);
	  		break;
	  	case 3:
	  		Display(head);
	  		break;
	  	case 4:
	  		exit(0);
	  	default:
	  		printf("Tryitng entering a valid choice!!");
	  }
	}
}

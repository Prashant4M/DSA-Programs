#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
	int data;
	struct Node *next;
};
int count1,count2;
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
	printf("\n");
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
int MakeNumber(NODE *root,int count)
{
	int num=0,n=count-1;
	while(root)
	{
		num+=(root->data)*pow(10,n);
		n--;
		root=root->next;
	}
	return num;
}

int main()
{
	NODE *head=NULL,*head1=NULL,*head2=NULL;
	int choice,value,choice1,Num1,Num2,n;
	while(1)
	{
	  printf("\nEnter your choice:");
	  printf("\n1.Insert\n2.Multiply two number reprsented by the list\n3.Display\n4.Exit\n");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the digit:");
	  		scanf("%d",&value);
	  		printf("1-In List 1\n2-In List 2\n");
	  		scanf("%d",&choice1);
	  		if(choice1==1)
	  		{
			 	MakeList(&head,value);
	  			count1++;
	  		}
	  		else
	  		{
				MakeList(&head1,value);
	  			count2++;
	  		}
	  		break;
	  	case 2:
	  		Num1=MakeNumber(head,count1);
	  		Num2=MakeNumber(head1,count2);
	  		n=Num1*Num2;
	  		while(n!=0)
	  		{
	  			MakeList(&head2,n%10);
	  			n=n/10;
			}
			Display(head2);
	  		break;
	  	case 3:
	  		Display(head);
	  		Display(head1);
	  		break;
	  	case 4:
	  		exit(0);
	  	default:
	  		printf("Tryitng entering a valid choice!!");
	  }
	}
}

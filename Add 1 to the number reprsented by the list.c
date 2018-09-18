#include<stdlib.h>
#include<stdio.h>
#include<math.h>
struct Node
{
	int data;
	struct Node *next;
};
int count=0;
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
int MakeNumber(NODE *root)
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
void main()
{
	NODE *head=NULL,*head1=NULL;
	int choice,value,OrginalNum,NumAfterAdding;
	while(1)
	{
	  printf("****************************************************\n");
	  printf("1.Enter a digit in the number represented by the list\n2.Add 1 to the number represented by the list\n3.Display the number\n4.Exit\n");
	  printf("****************************************************\n");
	  printf("\nEnter your choice:");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the digit:");
	  		scanf("%d",&value);
	  		MakeList(&head,value);
	  		count++;
	  		break;
	  	case 2:
	  		OrginalNum=MakeNumber(head);
	  		NumAfterAdding=OrginalNum+1;
	  		while(NumAfterAdding!=0)
	  		{
	  			MakeList(&head1,NumAfterAdding%10);
	  			NumAfterAdding/=10;
		    }
		    printf("List After adding 1 to the number %d:\n",OrginalNum);
		    Display(head1);
	  		break;
	  	case 3:
	  		Display(head);
	  		break;
	  	case 4:
	  		exit(0);
	  	default:
	  		printf("Tryitng entering a valid choice!!\n");
	  }
	}
}

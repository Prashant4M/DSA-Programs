#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node *prev;
	struct Node *next;
};
typedef struct Node NODE;
void Insert(NODE **,int);
void Delete(NODE **);
void Display(NODE *);
void Reverse(NODE **);
int main()
{
	NODE *head=NULL;
	int value,choice,delvalue;
	while(1)
	{
	  printf("\n**************MENU******************\n");
	  printf("1.Insertion\n2.Deletion\n3.Display\n4.Reverse\n5.Exit");
	  printf("\n************************************\n");
   	  printf("Enter your choice:");
   	  scanf("%d",&choice);
	  switch(choice)
	  {
	  	case 1:
	  		printf("Enter the value to insert:");
	  		scanf("%d",&value);
	  		Insert(&head,value);
	  		break;
	  	case 2:
	  		Delete(&head);
	  		break;
	  	case 3:
	  		Display(head);
	  		break;
	  	case 4:
	  		Reverse(&head);
	  		break;
	  	case 5:
	  		exit(0);
	  	default:
	  		printf("Try entering a valid choice.");
	  		break;
	  }
}
}
void Insert(NODE **root,int n)
{
	NODE *temp=(NODE *)malloc(sizeof(NODE)),*p=*root;
	temp->info=n;
	int choice,i,position;
	if(*root==NULL)
   	{
    	temp->prev=NULL;
    	temp->next=NULL;
    	*root=temp;
    	printf("First Node Created..");
    	return;
    }
	printf("Enter the position to insert:1-Beginning  2-In Between  3-at End\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			temp->next=*root;
			(*root)->prev=temp;
			*root=temp;
			printf("Node Inserted.");
			break;
		case 2:
			printf("Enter the positon to insert the node:");
			scanf("%d",&position);
			for(i=1;i<position-1 && p;i++)
			{
				p=p->next;
			}
			if(!p)
			{
		      printf("Position is beyond the size of the list.");
		      return;
			}
			temp->next=p->next;
			p->next=temp;
			p->next->prev=temp;
			temp->prev=p;
			printf("Value Inserted.");
			break;
		case 3:
			while(p->next)
			{
				p=p->next;
			}
			p->next=temp;
			temp->prev=p;
			temp->next=NULL;
			printf("Value inserted!!");
			break;
	}
}
void Delete(NODE **root)
{
	int position,k=1,delvalue,choice;
	NODE *p=*root,*temp=*root,*temp1;
	if(!*root)
	{
		printf("List is Empty!!");
		return;
	}
	printf("\n1.Delete From Begining\n2.Delete From End\n3.Delete from specified position\n4.Deleting with a given key\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:{
			(*root)=(*root)->next;
			if(*root!=NULL)
			{
				(*root)->prev=NULL;
			}
			free(temp);
			printf("Node has been deleted!!");
			break;
		}
		case 2:{
			while(p->next)
			{
				p=p->next;
			}
			temp1=p->prev;
			temp1->next=NULL;
			p->prev=NULL;
			free(p);
			printf("Node has been deleted!!");
			break;
		}
		case 3:{
			printf("Enter position to delete:");
			scanf("%d",&position);
			while(p && k<position)
			{
				p=p->next;
				k++;
			}
			temp1=p->prev;
			temp1->next=p->next;
			p->next->prev=temp1;
			free(p);
			printf("Node has been deleted!!");
			break;
			case 4:{
				printf("Enter the value to delete:");
				scanf("%d",&delvalue);
				while(p)
				{
					if(p->info==delvalue)
					{
					p->prev->next=p->next;
					p->next->prev=p->prev;
					printf("Node has been deleted!!\n");
					return;	
					}
					p=p->next;
				}
				printf("Key is not present in the list!!");
				break;
			}
		}
	}
}
void Display(NODE *root)
{
	while(root)
	{
		printf("%d\t",root->info);
		root=root->next;
	}
}
void Reverse(NODE **root)
{
	NODE *current=*root,*temp=NULL;
	while(current)
	{
		temp=current->prev;
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	if(temp)
	{
	(*root)=temp->prev;
	}
	printf("List has been reversed.");
}

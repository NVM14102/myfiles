#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL, *end=NULL;
int count=0;
void create_nodes();
void display();
void create_nodes()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=end=newnode;
		end->next=newnode;
	}
	else
	{
		end->next=newnode;
		end=newnode;
		end->next=head;
	}
	count++;
	printf("\nNode is created");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	temp=head;
	printf("\nList is ");
	do{
		printf("%d ->",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
void insert_first()
{
	int info;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n Memory allocation failed");
		return;
	}
	printf("\nEnter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=head;
	head=newnode;
	end->next=head;
	count++;
	printf("\nNode is added");
}
void insert_last()
{
	int info1;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n Memory allocation failed");
		return;
	}
	printf("\nEnter data into node:");
	scanf("%d",&info1);
	newnode->data=info1;
	end->next=newnode;
	end=newnode;
	newnode->next=head;
	count++;
	printf("\nNode is added");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n****MENU****");
		printf("\n1.Create\n2.Display\n3.Insert first node\n4.Insert node at end\n");
		printf("5.Insert node at any pos\n6.No.of nodes\n7.Delete first node\n");
		printf("8.Delete last node\n9.Delete any node\n10.Search element\n11.Replace element\n12.Exit");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create_nodes();break;
			case 2: display();break;
		    case 3: insert_first();break;
		    case 4: insert_last();break;
			case 12: exit(0);
	        default:printf("\n Invalid choice");
		}//end of switch
	}//end of while
	return 0;
}

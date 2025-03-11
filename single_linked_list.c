#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL, *end=NULL;
void create_nodes();
void display();
int count=0;
void create_nodes()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory full");
		return;
	}
	printf("\nEnter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		end=newnode;
	}
	count++;
	printf("\nNode created or added");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty");
		return;
	}
	temp=head;
	printf("\nList elements are:");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}//end of display()
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
	newnode->next=NULL;
	end->next=newnode;
	end=newnode;
	count++;
	printf("\nNode is added");
}
void insert_anypos()
{
	int info,pos,i;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation failed\n");
		return;
	}
	printf("\nEnter data into node:");
	scanf("%d",&info);
	printf("\nEnter position to insert:");
	scanf("%d",&pos);
	newnode->data=info;
	newnode->next=NULL;
	if(pos < 1 || pos > count + 1)
	{
		printf("Invalid position!\n");
		free(newnode);
		return;
	}
	struct node* temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
	printf("\nNode is added");
}
void delete_first()
{
	if(head==NULL)
	{
		printf("Empty");
		return;
	}
	struct node *temp=head;
	head=head->next;
	free (temp);
	count--;
	printf("\nNode is deleted");
}
void delete_last()
{ 
	if(head==NULL)
	{
		printf("Empty");
		return;
	}
	struct node *prev,*curr;
	curr=head;
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
   prev->next=NULL;
   free(curr);
   end=prev;
   count--;
   printf("\nNode is deleted");
}
void delete_anypos()
{
	int i,pos;
	if(head==NULL)
	{
		printf("Empty");
		return;
	}
	printf("\nEnter position to delete:");
	scanf("%d",&pos);
    if(pos < 1 || pos > count)
	{
		printf("Invalid\n");
		return;
	}
	struct node *prev,*curr;
	curr=head;
	for(i=1;i<pos;i++)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;
	free(curr); 
	count--;
	printf("\nNode is deleted");
}
void search()
{
	int key;
	if(head==NULL)
	{
		printf("Empty");
		return;
	}
	printf("\nEnter element to search:");
	scanf("%d",&key);
	int found=0;
	struct node *curr=head;
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			printf("Element found");
			return;
			found=1;
		}
	 curr=curr->next;
	}
	if(found==0)
	{
		printf("Element not found");
	}
}
void replace()
{
	int key,rep;
	if(head==NULL)
	{
		printf("Empty");
		return;
	}
	printf("\nEnter element to search:");
	scanf("%d",&key);
	printf("\nEnter element to replace:");
	scanf("%d",&rep);
	struct node *curr=head;
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			curr->data=rep;
			printf("Element is replaced");
			return;
		}
		curr=curr->next;
	}
	printf("Element is not found");
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
			case 5: insert_anypos();break;
		        case 6: printf("\n Total nodes:%d",count);break; 
		        case 7: delete_first();break;
		        case 8: delete_last();break;
		        case 9: delete_anypos();break;
		        case 10: search();break;
		        case 11: replace();break;
		case 12: exit(0);
	        default:printf("\n Invalid choice");
		}				//end of switch
	}				//end of while
	return 0;
}					//enf of main

#include <stdio.h>
#include <stdlib.h>
struct node {
   int data;
   struct node *next;
};
struct node *head = NULL,*end = NULL;
int count=0;

void create_nodes();

// display the list
void display();
void display(){
   struct node *temp = head;
   if(head==NULL)
   {
   	printf("\n List is empty..");
   }
   else
   {
   printf("\nThe list elements are  ");
   while(temp != NULL) {
      printf(" %d->",temp->data);
      temp = temp->next;
   }
  }
  printf("NULL");
}


//Creating nodes
void create_nodes(){
	int info;
   struct node *newnode;
   newnode = (struct node*) malloc(sizeof(struct node));
   if(newnode==NULL)
   {
   	printf("\n Memory Not allotted..");
   	return;
   }
   printf("\n Enter data into a node..");
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
   printf("\nNode is created or added ");
}

//inserting from begining//
void insert_beg()
{
   int info;
   struct node *newnode;
   newnode = (struct node*) malloc(sizeof(struct node));
   if(newnode==NULL)
   {
   	printf("\n Memory Not allotted..");
   	return;
   }
   printf("\n Enter data into a node..");
   scanf("%d",&info);
   newnode->data=info;
   newnode->next = head;;
   head = newnode;
   count++;
   printf("\nNode is inserted at the begining");	
}

//insert at the end
void insert_end()
{
int info;
   struct node *newnode;
   newnode = (struct node*) malloc(sizeof(struct node));
   if(newnode==NULL)
   {
   	printf("\n Memory Not allotted..");
   	return;
   }
   printf("\n Enter data into a node..");
   scanf("%d",&info);
   newnode->data=info;
   newnode->next=NULL;
   if(head==NULL)
   {
   	head=end=newnode;
   }
   else
   {
   end->next = newnode;
   end = newnode;
   }
   count++;
   printf("\nNode is inserted at the end");	
}

//insertion at any point
void insert_at_any_point()
{
int info,pos,i;

   printf("Enter position:");
   scanf("%d",&pos);
   if(pos<1||pos>count)
   {
   	printf("Cant insert");
   	return;
   }
   
   struct node *newnode, *temp;
   newnode = (struct node*) malloc(sizeof(struct node));
   if(newnode==NULL)
   {
   	printf("\n Memory Not allotted..");
   	return;
   }
   printf("\n Enter data into a node..");
   scanf("%d",&info);
   newnode->data=info;
   newnode->next=NULL;
   temp = head;
   for(i=0;i<pos-1;i++)
   {
   	temp = temp->next;
   }
   newnode->next = temp->next;
   temp -> next = newnode;
   count++;
   printf("\nNode is inserted at %d position",pos);	
}

//delete node at begining
void delete_beg()
{
   struct node *temp;
   if(head==NULL)
   {
   	printf("\nList is empty");
   	return;
   }
   temp = head;
   head = head-> next;
   free(temp);
   count--;
   printf("Node deleted at the start") ;		
}

//delete node at the end
void delete_end()
{
	struct node *current,*previous;
	if(head==NULL)
	{
		printf("List is Empty");
		return;
	}
	current=head;
	while(current->next!=NULL)
	{
		previous=current;
		current=current->next;
	}
	previous->next=NULL;
	end=previous;
	free(current);
	count--;
	printf("node is deleted");
}
//delete node at any point

int main(){
   	  int ch;
      while(1)
      {
      	printf("\nMENU");
     	printf("\n1.Create node: \n2.Display \n3.Insert at the end \n4.Insert at the begining \n5.Count the no of nodes");
		printf("\n6.Insert at any point \n7.Delete at the first \n8.Delete at the end \n11.Exit");
      	printf("\n\nEnter Your Choice:");
      	scanf("%d",&ch);
      	switch(ch)
      	{
      		case 1: create_nodes(); break;
      		case 2:	display(); break;
      		case 3: insert_end();break;
      		case 4: insert_beg();break;
      		case 5: printf("\n No.of nodes are : %d",count); break;
      		case 6: insert_at_any_point();break;
      		case 7: delete_beg();break;
      		case 8: delete_end();break;
      		case 11: exit(0);
      		default: printf("\nInvalid choice");
		  }
	  }
	  return 0;
}


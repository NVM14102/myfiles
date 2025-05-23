//STACK IMPLEMENTATION USING ARRAY 				-by NVM

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int top=-1;
int stack[SIZE];
int size =0;
//all operations of stack 
void push();
int pop();
int peek();
void display();

void isEmpty();
void isFull();
// push operation
void push(int ele)
{
	if(top==SIZE-1)
	{
		printf("\n ===STACK IS OVER_FLOW=== \n Elements Cannot be Added to this Stack......\n");
		
	}else{
		top++;
		stack[top]=ele;
		
	    printf("\n%d is Added to %d positon in Stack \n",ele,top);
	    size ++;
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("\n ===STACK IS EMPTY=== \n");
	}else{
		printf("\n The Stack elements are :\n");
		for(i=top;i>=0;i--)
		{
			printf(" \t| %d |\n",stack[i]);
		}
	}
}//end of display
void isEmpty(){
	if(top ==-1){
		printf("STACK IS EMPTY");
	}
	else{
		printf("STACK IS NOT EMPTY");
	}
}
void isFull() {
    if (top == SIZE - 1) {
        printf("STACK IS FULL\n");
    } else {
        printf("STACK IS NOT FULL\n");
    }
}
int pop()
{
	int x;
	if(top==-1)
	{
		printf("\n==STACK IS UNDER_FLOW==\n Stack is already empty.....\n");
		return -1;
	}else{
		x=stack[top];
		top--;
		size--;
	}
	return x;
}
int peek()
{
	int x;
	if(top==-1)
	{
		printf("\n==STACK IS EMPTY==");
		return -1;
	}else{
		x=stack[top];
	}
	return x;
}

int main()
{
	int ch,i,x;
	do{
		printf("\n<-----ALL_STACK_OPERATIONS----by Array->\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.SIZE\n6.IsEmpty\n7.IsFull\n10.EXIT\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			        printf("\nEnter element:");
			        scanf("%d",&x);
			        push(x);
			        break;
			case 2:
			        x=pop();
					if(x!=-1)
				        printf("\n-Popped element is => %d",x);
					break;
			case 3:
			         x=peek();
					if(x!=-1)
				        printf("\n The Peek  element is --> %d",x);
					break;
			case 4:
				    display();
				    break;	    
			case 5:
					printf("Stack size is = %d",size);
					break;
			case 6:
				isEmpty();
				break;
			case 7:
			    isFull();
			    break;
			case 10:
				    printf("\nThank you. Visit again.!\n");
				    exit(0);
			default:
				    printf("\nInvalid choice");
		}
	}while(1);
	return 0;
}//end of main

<-------------------------------------------------------------------------------------------------------------------------------------->

//STACK IMPLEMENTATION USING LINKED LIST      -by NVM

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;

void push() {
    int val;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Unable to push the element. Memory allocation failed.\n");
        return;
    }

    printf("Enter the value to push: ");
    scanf("%d", &val);

    ptr->val = val;
    ptr->next = head; 
    head = ptr;     

    printf("Item %d pushed to stack\n", val);
}

void pop() {
    if (head == NULL) {
        printf("Underflow: Stack is empty\n");
        return;
    }

    struct node* ptr = head;
    int item = head->val;

    head = head->next;  // Move the head pointer to the next node
    free(ptr);          // Free the memory of the popped node

    printf("Item %d popped from stack\n", item);
}

void peek() {
    if (head == NULL) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element is: %d\n", head->val);
    }
}

void display() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Stack elements: \n");
    while (temp != NULL) {
        printf("\t\n | %d |\t ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty() {
    return (head == NULL);
}

int size() {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice;
    while (1) {
        printf("\n<---ALL_STACK_OPERATIONS--by linked_list->\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. is Empty\n6. Get Stack Size\n7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                printf("Stack size: %d\n", size());
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

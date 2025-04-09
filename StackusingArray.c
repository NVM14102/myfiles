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
		printf("\n<-----ALL_STACK_OPERATIONS----->\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.SIZE\n6.IsEmpty\n7.IsFull\n10.EXIT\n");
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

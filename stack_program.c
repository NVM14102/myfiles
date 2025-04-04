#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int top=-1;
int stack[SIZE];
void push();
int pop();
int peek();
void display();

void push(int ele)
{
	if(top==SIZE-1)
	{
		printf("\nstack is full");
	}else{
		top++;
		stack[top]=ele;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\nstack is full");
	}else{
		printf("\nstack elements are:");
		for(i=0;i<=top;i++)
		{
			printf("\t%d\n",stack[i]);
		}
	}
}//end of display
int pop()
{
	int x;
	if(top==-1)
	{
		printf("\nstack is full");
		return -1;
	}else{
		x=stack[top];
		top--;
	}
	return x;
}
int peek()
{
	int x;
	if(top==-1)
	{
		printf("\nstack is full");
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
		printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
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
				        printf("\npopped element is %d",x);
					break;
			case 3:
			         x=peek();
					if(x!=-1)
				        printf("\npopped element is %d",x);
					break;
			case 4:
				    display();
				    break;
			case 5:
				    printf("\nThank you. Visit again.!\n");
				    exit(0);
			default:
				    printf("\nInvalid choice");
		}
	}while(1);
	return 0;
}//end of main

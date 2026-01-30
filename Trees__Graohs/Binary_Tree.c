#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;

};
struct node * newnode;

struct node * createnode(){
	newnode =malloc(sizeof(struct node));
	int x;
	printf("Enter data into the node ");
	scanf("%d",&x);
	printf("Enter -1 for leaf nodes----->\n");
	
	if(x==-1){
		return 0;
	}
	else{
		newnode->data =x;
		
		printf("Enter LEFT_CHILD of %d",x);
		newnode->left = createnode();
		printf("Enter RIGHT_CHILD of %d",x);
		newnode->right = createnode();
	}
}
int main(){
	struct node * root = NULL; 
	createnode();
	
	return 0;
}

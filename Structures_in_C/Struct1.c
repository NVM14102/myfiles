#include<stdio.h>
#include<string.h>

int main(){
	struct student{
	int rno;
	char name[20];
	int marks;
};
	struct student s[30]; 	
	int i,n;
	printf("Enter the No.of Students :");
	scanf("%d",&n);
	for(i=0;i<n; i++){
		printf("Enter student %d Detauls \n\n",i+1);
		printf("Enter Roll No :\n ");
		scanf("%d",&s[i].rno);
		
		printf("Enter Student Name :\n");
		scanf("%s",s[i].name);
		
		printf("Enter Student Marks :\n");
		scanf("%d",&s[i].marks);
	}
	printf("<-----Student Details---->\n");
	printf("Name   \t Roll_No    \t Marks \n");
	for(i=0;i<n;i++){
		printf("%s   \t",s[i].name);
		printf("%d 	 \t",s[i].rno);
		printf("%d 	 \t",s[i].marks);		// Printting the values
	}
	return 0;
}

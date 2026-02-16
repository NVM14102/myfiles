#include<stdio.h>
#include<string.h>
struct student{
	int rno;
	char name[20];
	int marks;
};
int main(){
struct student s; 		//Creating the variable to the structure

//strcpy(s.name,"manikanta");		// Initilize the valudes
//s.marks=200;
//s.rno =101;
printf("Enter Student Name :\n");
scanf("%s",s.name);

printf("Enter Roll No :\n ");
scanf("%d",& s.rno);

printf("Enter Student Marks :\n");
scanf("%d",&s.marks);

printf("<-----Student Details---->\n");
//printf("%s \n",s.name);
//printf("%d \n",s.marks);		// Printting the values
//printf("%d \n",s.rno);
printf("Name   \t Roll_No    \t Marks \n");
printf("%s       %d            %d ",s.name,s.rno,s.marks);
return 0;
}

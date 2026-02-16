#include<stdio.h>
#include<string.h>
	
	struct student{
		char name[20];
		int roll;
		int marks;
	};
	// Assume that it  like a class 	
	int main(){
		struct student s; // creating Object 
		//		s.marks=10;
		//		s.roll=1001122;		// Accessing Elements
		//		
		////		strcpy(name ="Manikanta",s.name);
		//		printf("student Roll No is %d \n",s.roll);
		//		printf("marks %d \n",s.marks);
	
		printf("Enter name:");
		scanf("%s ",s.name);
		
		printf("Enter Roll NO :");
		scanf("%d ",&s.roll);
		
		printf("Enter Marks :");
		scanf("%d",&s.marks);
		
		printf("-----student Details-----\n");
		printf("Name :%s\n ",s.name);
		printf("Roll No :%d \n",s.roll);
		printf("Marks :%d \n",s.marks);
		
		return 0;
}

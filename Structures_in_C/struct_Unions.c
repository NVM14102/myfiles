#include<stdio.h>
						//union student{
struct student{

//	char sname[10];
	int marks;
	int id;
	float percentage;

};
int main(){
					//union student s1;
struct student s1;
	
	printf("%d",sizeof(s1));
	
	return 0;
}

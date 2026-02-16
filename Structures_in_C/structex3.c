#include<stdio.h>
//struct student {
//	int rno;	//int size 4 bytes
//	char name[20]; // char 1 byte 20 *1
//	int marks;	//4 bytes
//};

struct DOB{
	int day:5;
	int month:4;
	int year;
};
int main(){
//	struct student s1 ={10,"manikanta",2999};;
//	printf("%d %s %d",s1.rno,s1.name,s1.marks);
	struct DOB dob;
	printf("%d",sizeof(dob));
	
}

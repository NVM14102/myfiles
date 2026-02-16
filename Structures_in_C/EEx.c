#include<stdio.h>
struct student 
{
	int rno;
	char sname[20];
};
struct placement {
	char c_name[10];
	float salary;
	char location[20];
	struct student s1;
};
int main(){
	struct placement p;
	
    printf("Enter Student Details: rno and name\n");
    scanf("%d %s", &p.s1.rno, p.s1.sname); // No & for sname since it's an array

    printf("Placement Details: c_name, salary, and location\n");
    scanf("%s %f %s", p.c_name, &p.salary, p.location);
	
	printf("Printing the Detailss----->");
	
	printf("Printing the Details----->\n");
    printf("Student Roll No: %d\n", p.s1.rno);
    printf("Student Name: %s\n", p.s1.sname);
    printf("Company Name: %s\n", p.c_name);
    printf("Salary: %.2f\n", p.salary);
    printf("Location: %s\n", p.location);
	
	return 0;
}

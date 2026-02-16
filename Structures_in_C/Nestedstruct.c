#include<stdio.h>
struct student 
{
	int rno;
	char sname;
};
struct placement {
	char c_name;
	float salary;
	char location;
	struct student s1;
};
int main(){
	struct placement p;
	
	printf("Enter Studetn Details :  rno and name \n");
	scanf("%d %s",&p.s1.rno,&p.s1.sname);
	printf("Placements   Details : c_name and salary and location \n");
	scanf("%s %f %s ",&p.c_name,&p.salary,&p.location);
	printf("Printing the Detailss----->");
	printf("%d\n %s\n",p.s1.rno,p.s1.sname);
	printf("%s\n %f\n %s\n",p.c_name,p.salary,p.location);
	
	
}

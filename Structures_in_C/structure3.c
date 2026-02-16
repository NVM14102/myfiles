#include<stdio.h>
struct student {
	int Rno;
	char name[20];
	char branch[10];
};
int mainn (){
	struct student s1={10,"manikanta","CSE"};
	struct student s2;
	s2 = s1;
	printf("%d\t%s\t%s",s1.Rno,s1.name,s1.branch);
}

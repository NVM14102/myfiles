#include<stdio.h>
#include<string.h>
struct student{
	int rno;
	char name[20];
	int marks;
	int math,cse,chem,phy;
	int Total;
	float Average;
};
int main(){
	struct student s[30]; 	
	int i,n;
	printf("Enter the No.of Students :");
	scanf("%d",&n);
	for(i=0;i<n; i++){
		printf("Enter student %d Detauls \n\n",i+1);
			
		printf("Enter Student i Name :\n");
		scanf("%s",s[i].name);
		
		printf("Enter Roll No :\n ");
		scanf("%d",&s[i].rno);
		
		printf("Enter Student Maths Marks:\n");
		scanf("%d",&s[i].math);
		
		printf("Enter Student CSE Marks :\n");
		scanf("%d",&s[i].cse);
		
		printf("Enter Student  Chemsitry Marks :\n");
		scanf("%d",&s[i].chem);
		
		printf("Enter Student  Physics Marks :\n");
		scanf("%d",&s[i].phy);
		
		s[i].Total =s[i].math + s[i].cse + s[i].chem + s[i].phy;
		printf("%d \n",s[i].Total);
	
		s[i].Average = s[i].Total/4.0;
	}

//	printf("%2f"\n,s[i].Average);
	
//	printf("<-----Student Details---->\n");
//	printf("R.No	\tName	\t Maths	\tCSE	\tChemistry 	\tPhysics 	\tTotal		\Average\n");
//	for(i=0;i<n;i++){
//		printf("%d		\t",s[i].rno);
//		printf("%s		\t",s[i].name);
//		printf("%d		\t",s[i].math);
//		printf("%d		\t",s[i].cse);
//		printf("%d 		\t",s[i].chem);
//		printf("%d		\t",s[i].phy);
//		printf("%d	  \t",s[i].Total);	
//		printf("%f     \t",s[i].Average);
    printf("\n<----- Student Details ----->\n");
    printf("R.No\tName\t\tMaths\tCSE\tChemistry\tPhysics\tTotal\tAverage\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t\t%d\t%d\t%d\t\t%d\t%d\t%.2f\n", 
        s[i].rno, s[i].name, s[i].math, s[i].cse, s[i].chem, s[i].phy, s[i].Total, s[i].Average);
    }
	
	
	return 0;
}

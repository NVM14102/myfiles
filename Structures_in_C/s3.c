#include <stdio.h>
#include <string.h>

struct student {
    int rno;
    char name[20];
    int math, cse, chem, phy;
    int Total;
    float Average;
};

int main() {
    struct student s1 = {1, "Alice", 90, 85, 88, 92, 0, 0.0};
    struct student s2;

    // Calculate Total and Average for s1
    s1.Total = s1.math + s1.cse + s1.chem + s1.phy;
    s1.Average = s1.Total / 4.0;

    // Copy the structure
    s2 = s1;

    // Display s2 (copied structure)
    printf("Details of Student 2 (Copied from Student 1):\n");
    printf("R.No: %d\n", s2.rno);
    printf("Name: %s\n", s2.name);
    printf("Math: %d\n", s2.math);
    printf("CSE: %d\n", s2.cse);
    printf("Chemistry: %d\n", s2.chem);
    printf("Physics: %d\n", s2.phy);
    printf("Total: %d\n", s2.Total);
    printf("Average: %.2f\n", s2.Average);

    return 0;
}


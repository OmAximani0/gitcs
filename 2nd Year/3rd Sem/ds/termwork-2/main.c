#include <stdio.h>
#include <strings.h>

struct Student
{
    char name[50];
    int cetRank;
    char branch[20];
};

void input(struct Student students[], int size);
void segregateStudents(struct Student students[], int n, char targetBranch[]);

void main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    printf("\nEnter student details: ");
    input(students, n);
    printf("---------\n");

    segregateStudents(students, n, "CSE");
    segregateStudents(students, n, "EC");
    segregateStudents(students, n, "EE");
    segregateStudents(students, n, "ME");
}

void segregateStudents(struct Student students[], int n, char targetBranch[])
{
    int studentAdmitted = 0;
    printf("\nStudent from %s brnach: ", targetBranch);
    for (int i = 0; i < n; ++i)
    {
        if (strcasecmp(students[i].branch, targetBranch) == 0)
        {
            studentAdmitted = 1;
            printf("\n\tStudent name: %s", students[i].name);
            printf("\n\tStudent rank: %d\n", students[i].cetRank);
        }
    }
    if (studentAdmitted == 0)
    {
        printf("\n\tNo student admitted for %s \n", targetBranch);
    }
}

void input(struct Student students[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("\nStudent name: ");
        scanf("%s", students[i].name);
        printf("Student branch: ");
        scanf("%s", students[i].branch);
        printf("Student rank: ");
        scanf("%d", &students[i].cetRank);
    }
}
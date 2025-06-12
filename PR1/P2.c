// Write a C program that takes a Student structure array [for example struct
// Student. Define an array called studentDt that consists of 10
// elements/students. Each element is defined to be of the type struct Student].
// The program should store marks of 5 subjects and calculate total and
// percentage for the student. Display each subject's marks, total and
// percentage for all students. Create separate functions for collecting,
// computing and displaying data

#include <stdio.h>

struct student
{
    char name[20];
    int marks[5];
    int total;
    float percentage;
};

void inputdata(struct student studentDt[])
{
    for (int i = 0; i < 2; i++)
    {
        printf("\n enter the name of student %d ", i + 1);
        scanf("%s", studentDt[i].name);
        for (int j = 0; j < 5; j++)
        {
            printf("\n enter the marks for subject %d ", j + 1);
            scanf("%d", &studentDt[i].marks[j]);
        }
    }
}

void showdata(struct student studentDt[])
{
    for (int i = 0; i < 2; i++)
    {
        printf("\n the name of student %d is %s", i + 1, studentDt[i].name);
        for (int j = 0; j < 5; j++)
        {
            printf("\n marks of subject %d is %d ", j + 1, studentDt[i].marks[j]);
        }
        printf("\n total of marks is %d", studentDt[i].total);
        printf("\n percentage of marks is %.2f ", studentDt[i].percentage);
    }
}

void calculatedata(struct student studentDt[])
{
    for (int i = 0; i < 2; i++)
    {
        studentDt[i].total = 0;
        for (int j = 0; j < 5; j++)
        {
            studentDt[i].total += studentDt[i].marks[j];
        }
        studentDt[i].percentage = (studentDt[i].total / 5);
    }
}

void separator(int a)
{
    if (a == 1)
    {
        printf("\n--------------------------------------\n");
    }
    else
    {
        printf("\n''''''''''''''''''''''''''''''''''''''''''\n");
    }
}

int main()
{
    struct student studentDt[2];
    inputdata(studentDt);
    separator(1);
    calculatedata(studentDt);
    separator(0);
    showdata(studentDt);
    return 0;
}
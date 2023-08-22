#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    int rollNo;
    char grade;
};

void readStudent(struct student s[], int index)
{
    printf("Enter student name: ");
    scanf("%s", s[index].name);
    printf("Enter roll number: ");
    scanf("%d", &s[index].rollNo);
    printf("Enter grade: ");
    scanf(" %c", &s[index].grade); // Notice the space before %c to consume the newline character
}

void displayStudent(struct student s)
{
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.rollNo);
    printf("Grade: %c\n", s.grade);
}

void sortStudents(struct student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].rollNo > arr[j + 1].rollNo)
            {
                // Swap the students
                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student students[n];

    // Reading student information
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(students, i);
    }

    // Sorting student information by roll number
    sortStudents(students, n);

    // Displaying sorted student information
    printf("\nSorted Student Information:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(students[i]);
    }

    return 0;
}

#include <stdio.h>

#define MAX 50

// Structure for student details
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Function to input student details
void inputStudents(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &(s + i)->rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", (s + i)->name);

        printf("Enter Marks: ");
        scanf("%f", &(s + i)->marks);
    }
}

// Function to display student details
void displayStudents(struct Student *s, int n) {
    printf("\n========== STUDENT RECORDS ==========\n");

    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.2f\n",
               (s + i)->rollNo,
               (s + i)->name,
               (s + i)->marks);
    }
}

int main() {
    struct Student students[MAX];
    int n;

    printf("===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of students!\n");
        return 0;
    }

    inputStudents(students, n);
    displayStudents(students, n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee *next;
};

struct Employee *head = NULL;

// Insert
void insert() {
    struct Employee *newNode;

    newNode = (struct Employee *)malloc(sizeof(struct Employee));

    printf("Enter Employee ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Salary: ");
    scanf("%f", &newNode->salary);

    newNode->next = head;
    head = newNode;

    printf("Employee inserted successfully.\n");
}

// Display
void display() {
    struct Employee *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("\nID: %d", temp->id);
        printf("\nName: %s", temp->name);
        printf("\nSalary: %.2f\n", temp->salary);

        temp = temp->next;
    }
}

// Search
void search() {
    int id;
    struct Employee *temp = head;

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Employee Found!\n");
            printf("ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("Salary: %.2f\n", temp->salary);
            return;
        }

        temp = temp->next;
    }

    printf("Employee not found.\n");
}

// Delete
void deleteEmployee() {
    int id;
    struct Employee *temp = head;
    struct Employee *prev = NULL;

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->id == id) {
        head = head->next;
        free(temp);
        printf("Employee deleted.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Employee deleted.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SINGLY LINKED LIST =====");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Search");
        printf("\n4. Delete");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteEmployee();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

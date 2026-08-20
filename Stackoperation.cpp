#include <stdio.h>
#include <string.h>
#define MAX 10
char stack[MAX][50];
int top = -1;
void push(char page[])
{
    if (top == MAX - 1)
        printf("History Full!\n");
    else
    {
        top++;
        strcpy(stack[top], page);
        printf("Visited: %s\n", page);
    }
}
void pop()
{
    if (top == -1)
        printf("No previous page!\n");
    else
    {
        printf("Back from: %s\n", stack[top]);
        top--;
        
        if (top >= 0)
            printf("Current page: %s\n", stack[top]);
    }
}
void peek()
{
    if (top == -1)
        printf("History Empty!\n");
    else
        printf("Current page: %s\n", stack[top]);
}
void display()
{
    int i;

    if (top == -1)
        printf("History Empty!\n");
    else
    {
        printf("Browser History:\n");

        for (i = top; i >= 0; i--)
            printf("%s\n", stack[i]);
    }
}
int main()
{
    int choice;
    char page[50];
    do
    {
        printf("\n1. Visit Page");
        printf("\n2. Back");
        printf("\n3. Current Page");
        printf("\n4. Display History");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter webpage: ");
                scanf("%s", page);
                push(page);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("Invalid choice!");
        }
    } while(choice != 5);
    return 0;
}

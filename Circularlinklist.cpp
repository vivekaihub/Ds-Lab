#include <iostream>
#include <cstring>
using namespace std;

struct Team
{
    int id;
    char name[50];
    Team *next;
};
Team *head = NULL;
Team *current = NULL;
void addTeam()
{
    Team *newTeam, *temp;
    newTeam = new Team;
    cout << "\nEnter Team ID: ";
    cin >> newTeam->id;
    cout << "Enter Team Name: ";
    cin >> newTeam->name;
    newTeam->next = NULL;
    if (head == NULL)
    {
        head = newTeam;
        newTeam->next = head;
        current = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newTeam;
        newTeam->next = head;
    }
    cout << "Team added successfully!\n";
}
void displayTeams()
{
    Team *temp;
    if (head == NULL)
    {
        cout << "\nNo teams available!\n";
        return;
    }
    temp = head;
    cout << "\n----- Tournament Teams -----\n";
    do
    {
        cout << "Team ID: " << temp->id
             << "  Team Name: " << temp->name << endl;
        temp = temp->next;
    } while (temp != head);
}
void nextTeam()
{
    if (current == NULL)
    {
        cout << "\nNo teams available!\n";
        return;
    }
    current = current->next;
    cout << "\nCurrent Team: "
         << current->name << endl;
}
void roundRobin()
{
    Team *first;
    Team *second;
    if (head == NULL)
    {
        cout << "\nNo teams available!\n";
        return;
    }
    first = head;
    cout << "\n===== ROUND ROBIN SCHEDULE =====\n";
    do
    {
        second = first->next;
        while (second != head)
        {
            cout << first->name << " vs " << second->name << endl;
            second = second->next;
        }
        first = first->next;
    } while (first != head);
}
int main()
{
    int choice;
    do
    {
        cout << "\n===== TOURNAMENT ROUND ROBIN =====\n";
        cout << "1. Add Team\n";
        cout << "2. Display Teams\n";
        cout << "3. Next Team\n";
        cout << "4. Generate Round Robin Schedule\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                addTeam();
                break;
            case 2:
                displayTeams();
                break;
            case 3:
                nextTeam();
                break;
            case 4:
                roundRobin();
                break;
            case 5:
                cout << "\nProgram ended.\n";
                break;
            default:
                cout << "\nInvalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}

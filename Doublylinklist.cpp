#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[50];
    struct Song *prev;
    struct Song *next;
};

struct Song *head = NULL;
struct Song *current = NULL;

// Add song
void addSong() {
    struct Song *newSong;

    newSong = (struct Song *)malloc(sizeof(struct Song));

    printf("Enter song name: ");
    scanf(" %[^\n]", newSong->name);

    newSong->prev = NULL;
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
        current = newSong;
    } else {
        struct Song *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newSong;
        newSong->prev = temp;
    }

    printf("Song added successfully.\n");
}

// Display playlist
void display() {
    struct Song *temp = head;

    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n===== MUSIC PLAYLIST =====\n");

    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

// Forward navigation
void forward() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
    }
    else if (current->next == NULL) {
        printf("Already at the last song.\n");
    }
    else {
        current = current->next;
        printf("Playing: %s\n", current->name);
    }
}

// Backward navigation
void backward() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
    }
    else if (current->prev == NULL) {
        printf("Already at the first song.\n");
    }
    else {
        current = current->prev;
        printf("Playing: %s\n", current->name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== MUSIC PLAYLIST =====");
        printf("\n1. Add Song");
        printf("\n2. Display Playlist");
        printf("\n3. Next Song");
        printf("\n4. Previous Song");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;

            case 2:
                display();
                break;

            case 3:
                forward();
                break;

            case 4:
                backward();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

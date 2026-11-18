write a program with following operation in q insert, delete and display, exit.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;


void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
    } else {
        if (front == -1) {
            front = 0; // Initialize front when inserting the first element
        }
        printf("Enter the element to insert: ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
        printf("%d inserted into the queue.\n", item);
    }
}


void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Queue is empty.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

//defining the queue structure
struct QueueNode {
    int data;
    struct QueueNode* next;
};

//declare front and rear
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function prototypes(insert,delete,print)
void initQueue(struct Queue* q);
void insert(struct Queue* q, int value);
int delete(struct Queue* q);
void printQueue(const struct Queue* q);
//main program
int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    int choice, value;
//loop through choices
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
//ask user for input
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&myQueue, value);
                break;
            case 2:
                if (myQueue.front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Deleted element: %d\n", delete(&myQueue));
                }
                break;
            case 3:
                printQueue(&myQueue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Insert an element at the rear of the queue
void insert(struct Queue* q, int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!newNode) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Inserted %d into the queue.\n", value);
}

// Delete an element from the front of the queue
int delete(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        exit(1);
    }

    struct QueueNode* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return value;
}

// Print the elements in the queue
void printQueue(const struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct QueueNode* current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
#include <stdio.h>

void enqueue();
void dequeue();
void display();

int arr[50], front = -1, rear = -1, max;

int main() {
    int choice;

    printf("Enter the maximum number of elements: ");
    scanf("%d", &max);

    do {
        printf("Enter the choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue() {
    int item;
    if ((rear + 1) % max == front) {
        printf("Overflow: Queue is full\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &item);
        if (front == -1 && rear == -1) {
            front = 0;
        }
        rear = (rear + 1) % max;
        arr[rear] = item;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow: Queue is empty\n");
    } else {
        int item = arr[front];
        printf("%d removed\n", item);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Empty Circular Queue: No elements to display\n");
    } else {
        printf("Elements of queue: ");

        // Display elements from front to rear
        int i;
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", arr[i]);
            }
        } else {
            // Display elements when front has crossed the rear (circular)
            for (i = front; i < max; i++) {
                printf("%d ", arr[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", arr[i]);
            }
        }

        printf("\nFront position: %d\n", front);
        printf("Rear position: %d\n", rear);
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#define N 5

void enq(int ele);
int dequeue();
void display();
int isEmpty();
int isFull();
int size();
int peek();

int Q[N];
int front = -1, rear = -1, ele;

void enq(int ele) {
    if (isFull()) {
        printf("Queue Overflow: Cannot insert element, queue is full!...\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0; // Queue is empty, set both front and rear to 0
            Q[rear] = ele;
        } else {
            rear = (rear + 1) % N; // Circular increment of rear
            Q[rear] = ele;
        }
        printf("%d is inserted to queue.\n", ele);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Queue is empty, no element to delete...\n");
        return -1; // No elements to dequeue
    } else {
        int ele = Q[front];
        if (front == rear) { // Only one element left in the queue
            front = rear = -1; // Reset the queue
        } else {
            front = (front + 1) % N; // Circular increment of front
        }
        return ele;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
    } else {
        int i = front;
        printf("Queue Elements: ");
        while (i != rear) {
            printf("%d ", Q[i]);
            i = (i + 1) % N; // Circular increment of index
        }
        printf("%d ", Q[rear]); // Print the last element
        printf("\n");
    }
}

int isEmpty() {
    return front == -1; // Queue is empty if front == -1
}

int isFull() {
    return (rear + 1) % N == front; // Queue is full if (rear + 1) % N == front
}

int size() {
    if (isEmpty()) {
        return 0;
    }
    if (rear >= front) {
        return rear - front + 1;
    } else {
        return N - front + rear + 1;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty, no element to peek.\n");
        return -1;
    } else {
        return Q[front]; // Return the element at the front of the queue
    }
}

int main() {
    int ch, x;
    while (1) {
        printf("\n<---Circular Queue Operations- by Array--->\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. isEmpty\n6. isFull\n7. Get Size\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter an element to insert into the queue: ");
                scanf("%d", &x);
                enq(x);
                break;
            case 2:
                x = dequeue();
                if (x != -1)
                    printf("%d is removed from the queue.\n", x);
                break;
            case 3:
                display();
                break;
            case 4:
                x = peek();
                if (x != -1)
                    printf("Element at the front of the queue is: %d\n", x);
                break;
            case 5:
                if (isEmpty())
                    printf("The queue is empty.\n");
                else
                    printf("The queue is not empty.\n");
                break;
            case 6:
                if (isFull())
                    printf("The queue is full.\n");
                else
                    printf("The queue is not full.\n");
                break;
            case 7:
                printf("The size of the queue is: %d\n", size());
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}



<------------------------------------------------------------------------------------------------------------------------------>

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function declarations
void enqueue(int ele);
int dequeue();
void display();
int isEmpty();
int peek();
int getSize();

int count = 0;

// Enqueue function
void enqueue(int ele) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = ele;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;  // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    count++;
    printf("%d is inserted into the queue.\n", ele);
}

// Dequeue function
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Queue is empty, no element to delete...\n");
        return -1;
    }

    int val;
    if (front == rear) {
        val = front->data;
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        val = temp->data;
        front = front->next;
        rear->next = front;  // Maintain circular link
        free(temp);
    }

    count--;
    return val;
}

// Display function
void display() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue Elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Peek function
int peek() {
    if (isEmpty()) {
        printf("Queue is empty, no element to peek.\n");
        return -1;
    }
    return front->data;
}

// isEmpty function
int isEmpty() {
    return front == NULL;
}

// Size function
int getSize() {
    return count;
}

int main() {
    int ch, x;

    while (1) {
        printf("\n<--- Circular Queue Using Linked List --->\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. isEmpty\n6. Get Size\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter an element to insert into the queue: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            x = dequeue();
            if (x != -1)
                printf("%d is removed from the queue.\n", x);
            break;
        case 3:
            display();
            break;
        case 4:
            x = peek();
            if (x != -1)
                printf("Element at the front of the queue is: %d\n", x);
            break;
        case 5:
            if (isEmpty())
                printf("The queue is empty.\n");
            else
                printf("The queue is not empty.\n");
            break;
        case 6:
            printf("The size of the queue is: %d\n", getSize());
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


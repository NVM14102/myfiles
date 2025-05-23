//QUEUE IMPLEMENTATON USING ARRAY

#include <stdio.h>
#include <stdlib.h>

#define N 5

int Q[N];
int front = -1, rear = -1;
int size = 0; 

// Function Declarations
void enqueue(int ele);
void dequeue();
void peek();
void display();
void isEmpty();
void isFull();
int getSize();

void enqueue(int ele) {
    if (rear == N - 1) {		//checking queue is Full
        printf("Queue is Over_Flow..\nElements cannot be inserted to the queue...\n");
    }
	else if (front == -1 && rear == -1) {
        front = rear = 0;
        Q[rear] = ele;			//If queue is Empty then update the FRONT and REAR varaibles
        size++; 
    } else {
        rear++;
        Q[rear] = ele;		//Alreadty queue has an element 
        size++; 
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Under_Flow..\nThere is no element in the queue...\n");
    } 
	else if (front == rear) {
        printf("%d is deleted\n", Q[front]);		//Both pointing to the SAME element in the QUEUE
        front = rear = -1;
        size--; 
    } else {
        printf("%d is deleted\n", Q[front]);
        front++;
        size--;
    }
}

void display() {
	int i;
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } 
	else {
        printf("The elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("|\t%d\t| ", Q[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("The Peek Element is: %d\n", Q[front]);
    }
}

void isEmpty() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue is Not Empty\n");
    }
}

void isFull() {
    if (rear == N - 1) {
        printf("Queue is Full\n");
    } else {
        printf("Queue is Not Full\n");
    }
}

int getSize() {
    return size;
}

int main() {
    int choice, element;

    while (1) {
        printf("\n<-- QUEUE OPERATIONS -by Array->\n");
        printf("1. ENQUEUE \n2. DEQUEUE \n3. PEEK\n4. DISPLAY\n5. isEMPTY\n6. isFULL\n7. getSIZE\n10. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            printf("Size of the Queue is: %d\n", getSize());
            break;
        case 10:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}



//<--------------------------------------------------------------------------------------------------------------------->

#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Utility functions
void enqueue(int ele);
void dequeue();
void peek();
void display();
void isEmpty();
int getSize();

int size = 0; // Queue size tracker

// Enqueue operation
void enqueue(int ele) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = ele;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
    printf("%d inserted into the queue.\n", ele);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue is Underflow..\nThere is no element in the queue...\n");
        return;
    }

    struct Node* temp = front;
    printf("%d is deleted\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    size--;
}

// Peek operation
void peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("The Peek Element is: %d\n", front->data);
    }
}

// Display operation
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;
    printf("The elements are:\n");

    while (temp != NULL) {
        printf("|\t%d\t| ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// isEmpty check
void isEmpty() {
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue is Not Empty\n");
    }
}

// Return queue size
int getSize() {
    return size;
}

int main() {
    int choice, element;

    while (1) {
        printf("\n<-- QUEUE OPERATIONS---by Linked_list-->\n");
        printf("1. ENQUEUE \n2. DEQUEUE \n3. PEEK\n4. DISPLAY\n5. isEMPTY\n6. getSIZE\n10. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            printf("Size of the Queue is: %d\n", getSize());
            break;
        case 10:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}






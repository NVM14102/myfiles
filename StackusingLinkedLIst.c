//Stack implementation using LinkedLise
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;

void push() {
    int val;
    struct node* ptr = (struct node*)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Unable to push the element. Memory allocation failed.\n");
        return;
    }

    printf("Enter the value to push: ");
    scanf("%d", &val);

    ptr->val = val;
    ptr->next = head; 
    head = ptr;     

    printf("Item %d pushed to stack\n", val);
}

void pop() {
    if (head == NULL) {
        printf("Underflow: Stack is empty\n");
        return;
    }

    struct node* ptr = head;
    int item = head->val;

    head = head->next;  // Move the head pointer to the next node
    free(ptr);          // Free the memory of the popped node

    printf("Item %d popped from stack\n", item);
}

void peek() {
    if (head == NULL) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element is: %d\n", head->val);
    }
}

void display() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Stack elements: \n");
    while (temp != NULL) {
        printf("\t\n | %d |\t ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty() {
    return (head == NULL);
}

int size() {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice;
    while (1) {
        printf("\n<---ALL_STACK_OPERATIONS--->\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. is Empty\n6. Get Stack Size\n7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
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
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                printf("Stack size: %d\n", size());
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

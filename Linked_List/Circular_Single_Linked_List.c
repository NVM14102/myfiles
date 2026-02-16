#include<stdio.h>
#include<stdlib.h>		//CIRCULAR_SINGLE_LINKED_LIST
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *end = NULL;
int count = 0;

void create_nodes();
void display();
void insert_first();
void insert_last();
void insert_at_pos();
void delete_first();
void delete_last();
void delete_at_pos();
void search_element();
void replace_element();
void node_count();

void create_nodes() {
    int info;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data into node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = NULL;

    if (head == NULL) {
        head = end = newnode;
        end->next = head;
    } else {
        end->next = newnode;
        end = newnode;
        end->next = head;
    }
    count++;
    printf("\nNode is created");
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty");
        return;
    }
    temp = head;
    printf("\nList is: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

}

void insert_first() {
    int info;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed");
        return;
    }
    printf("\nEnter data into node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = head;
    head = newnode;
    end->next = head;  // update end node's next to head
    count++;
    printf("\nNode is added at the beginning");
}

void insert_last() {
    int info;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed");
        return;
    }
    printf("\nEnter data into node: ");
    scanf("%d", &info);
    newnode->data = info;
    end->next = newnode;
    end = newnode;
    end->next = head;  // update last node's next to head
    count++;
    printf("\nNode is added at the end");
}

void insert_at_pos() {
    int pos, info, i = 1;
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed");
        return;
    }
    printf("\nEnter position to insert: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count + 1) {
        printf("\nInvalid position");
        return;
    }
    printf("\nEnter data into node: ");
    scanf("%d", &info);
    newnode->data = info;

    if (pos == 1) {
        insert_first();  // if pos is 1, we use insert_first function
        return;
    }

    temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    count++;
    printf("\nNode is inserted at position %d", pos);
}

void delete_first() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    if (head == end) {  // only one node in the list
        free(head);
        head = end = NULL;
    } else {
        temp = head;
        head = head->next;
        end->next = head;
        free(temp);
    }
    count--;
    printf("\nFirst node is deleted");
}

void delete_last() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    if (head == end) {  // only one node in the list
        free(head);
        head = end = NULL;
    } else {
        temp = head;
        while (temp->next != end) {
            temp = temp->next;
        }
        temp->next = head;
        free(end);
        end = temp;
    }
    count--;
    printf("\nLast node is deleted");
}

void delete_at_pos() {
    int pos, i = 1;
    struct node *temp, *prev;
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count) {
        printf("\nInvalid position");
        return;
    }
    if (pos == 1) {
        delete_first();  // if pos is 1, use delete_first function
        return;
    }
    temp = head;
    while (i < pos) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    if (temp == end) {  // if deleting the last node
        end = prev;
    }
    free(temp);
    count--;
    printf("\nNode at position %d is deleted", pos);
}

void search_element() {
    int key, found = 0;
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    temp = head;
    do {
        if (temp->data == key) {
            printf("\nElement %d found in the list", key);
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found) {
        printf("\nElement %d not found", key);
    }
}

void replace_element() {
    int old_val, new_val, found = 0;
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }
    printf("\nEnter element to replace: ");
    scanf("%d", &old_val);
    printf("\nEnter new value: ");
    scanf("%d", &new_val);
    temp = head;
    do {
        if (temp->data == old_val) {
            temp->data = new_val;
            printf("\nElement %d replaced with %d", old_val, new_val);
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (!found) {
        printf("\nElement %d not found", old_val);
    }
}

void node_count() {
    printf("\nNumber of nodes: %d", count);
}

int main() {
    int ch;
    while (1) {
        printf("\n<---ALL CIRCULAR_SINGLE_LINKED_LIST OPERATIONS--->\n");
        printf("\n1.Create\n2.DISPLAY \n3.Insert AT_FIRST\n4.Insert AT_END\n");
        printf("5.Insert AT_ANY_POS\n6.SIZE\n7.Delete AT_FIRST\n");
        printf("8.Delete AT_LAST\n9.Delete ANY_NODE\n10.Search an Element\n11.Replace Element\n12.Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create_nodes(); break;
            case 2: display(); break;
            case 3: insert_first(); break;
            case 4: insert_last(); break;
            case 5: insert_at_pos(); break;
            case 6: node_count(); break;
            case 7: delete_first(); break;
            case 8: delete_last(); break;
            case 9: delete_at_pos(); break;
            case 10: search_element(); break;
            case 11: replace_element(); break;
            case 12: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
    return 0;
}

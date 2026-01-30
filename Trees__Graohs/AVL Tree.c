#include <stdio.h>
#include <stdlib.h>

#define SPACE 5

struct node {
    int data;
    struct node *left, *right;
    int height;
};

struct node* root = NULL;

/* Utility */
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node* NODE) {
    if (NODE == NULL)
        return 0;
    return NODE->height;
}

struct node* newNode(int x) {
    struct node* NODE = (struct node*)malloc(sizeof(struct node));
    NODE->data = x;
    NODE->left = NODE->right = NULL;
    NODE->height = 1;
    return NODE;
}

/* Rotations */
struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct node* NODE) {
    if (NODE == NULL)
        return 0;
    return height(NODE->left) - height(NODE->right);
}

/* Insert */
struct node* insert(struct node* NODE, int key) {
    if (NODE == NULL)
        return newNode(key);

    if (key < NODE->data)
        NODE->left = insert(NODE->left, key);
    else if (key > NODE->data)
        NODE->right = insert(NODE->right, key);
    else
        return NODE;

    NODE->height = 1 + max(height(NODE->left), height(NODE->right));
    int balance = getBalance(NODE);

    // LL
    if (balance > 1 && key < NODE->left->data)
        return rightRotate(NODE);

    // RR
    if (balance < -1 && key > NODE->right->data)
        return leftRotate(NODE);

    // LR
    if (balance > 1 && key > NODE->left->data) {
        NODE->left = leftRotate(NODE->left);
        return rightRotate(NODE);
    }

    // RL
    if (balance < -1 && key < NODE->right->data) {
        NODE->right = rightRotate(NODE->right);
        return leftRotate(NODE);
    }

    return NODE;
}

/* Inorder Traversal */
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Count nodes */
int countNodes(struct node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* Print Tree Pattern */
void printTree(struct node* root, int space) {
    if (root == NULL) return;

    space += SPACE;
    printTree(root->right, space);

    printf("\n");
    for (int i = SPACE; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

/* Main */
int main() {
    int ch, x;

    while (1) {
        printf("\n\n--- AVL MENU ---");
        printf("\n1.Insert");
        printf("\n2.Inorder Traversal");
        printf("\n3.Print Tree Pattern");
        printf("\n4.Count Nodes");
        printf("\n5.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                printTree(root, 0);
                break;
            case 4:
                printf("Number of nodes: %d", countNodes(root));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}


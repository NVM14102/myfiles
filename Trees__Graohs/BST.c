#include <stdio.h>
#include <stdlib.h>

#define SPACE 5

struct node {
    int data;
    struct node *left, *right;
};

struct node* root = NULL;

/* Create new node */
struct node* newNode(int x) {
    struct node* NODE = (struct node*)malloc(sizeof(struct node));
    NODE->data = x;
    NODE->left = NODE->right = NULL;
    return NODE;
}

/* Insert */
struct node* insert(struct node* root, int x) {
    if (root == NULL)
        return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

/* Traversals */
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* Search */
int search(struct node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

/* Find Minimum */
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* Delete Node */
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* NODE = root->right;
            free(root);
            return NODE;
        } else if (root->right == NULL) {
            struct node* NODE = root->left;
            free(root);
            return NODE;
        }
        struct node* NODE = findMin(root->right);
        root->data = NODE->data;
        root->right = deleteNode(root->right, NODE->data);
    }
    return root;
}

/* Height */
int height(struct node* root) {
    if (root == NULL)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
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
        printf("\n--- BST MENU ---");
        printf("\n1.Insert");
        printf("\n2.Inorder Traversal");
        printf("\n3.Preorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Search");
        printf("\n6.Delete");
        printf("\n7.Height");
        printf("\n8.Print Tree Pattern");
        printf("\n9.Count Nodes");
        printf("\n10.Exit");

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
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("Enter key: ");
                scanf("%d", &x);
                if (search(root, x))
                    printf("FOUND");
                else
                    printf("NOT FOUND");
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;
            case 7:
                printf("Height: %d", height(root));
                break;
            case 8:
                printTree(root, 0);
                break;
            case 9:
                printf("Number of nodes: %d", countNodes(root));
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}


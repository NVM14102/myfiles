#include <stdio.h>
#include <stdlib.h>

/* Structure */
struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

//Create Tree 
struct node* create() {
    int x;
    printf("Enter data (-1 for NULL): ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;

    printf("Enter LEFT child of %d\n", x);
    temp->left = create();

    printf("Enter RIGHT child of %d\n", x);
    temp->right = create();

    return temp;
}

//Traversals 
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

//Count Nodes 
int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//Count Leaf Nodes 
int countLeaf(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

//Search 
int search(struct node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    return search(root->left, key) || search(root->right, key);
}

//Height
int height(struct node* root) {
    if (root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

#define SPACE 5

void printTree(struct node* root, int space) {
    if (root == NULL)
        return;

    space += SPACE;

    /* Print right child first */
    printTree(root->right, space);

    printf("\n");
    for (int i = SPACE; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);

    /* Print left child */
    printTree(root->left, space);
}

/* Main */
int main() {
    int ch, key;

    while (1) {
        printf("\n------ General Binary Tree ------");
        printf("\n1. Create Tree");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Count Total Nodes");
        printf("\n6. Count Leaf Nodes");
        printf("\n7. Search Element");
        printf("\n8. Height of Tree");
        printf("\n9. Print Tree Pattern");
        printf("\n10. Number of Nodes");
        printf("\n11. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                root = create();
                break;
            case 2:
                printf("Preorder: ");
                preorder(root);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                break;
            case 5:
                printf("Total Nodes: %d", countNodes(root));
                break;
            case 6:
                printf("Leaf Nodes: %d", countLeaf(root));
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Element FOUND");
                else
                    printf("Element NOT FOUND");
                break;
            case 8:
                printf("Height of Tree: %d", height(root));
                break;
            case 9:
                printTree(root, 0);
                break;
            case 10:
                printf("Number of Nodes in the Tree: %d", countNodes(root));
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid Choice!");
        }
    }
}


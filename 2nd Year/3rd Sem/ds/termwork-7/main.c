#include <stdio.h>
#include <stdlib.h>

// Structure for the node of the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function for pre-order traversal
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for in-order traversal
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Function for post-order traversal
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Pre-order Traversal\n");
        printf("4. In-order Traversal\n");
        printf("5. Post-order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter an integer to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d is found in the BST.\n", value);
                } else {
                    printf("%d is not found in the BST.\n", value);
                }
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 4:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}


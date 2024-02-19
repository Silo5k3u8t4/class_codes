#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int key;
    struct TreeNode *left, *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Function to search for a key in the BST
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Function to find the minimum value node in a BST
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to delete a key from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest
        // in the right subtree)
        struct TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to find the largest element in the BST
struct TreeNode* findLargest(struct TreeNode* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return findLargest(root->right);
}

// Example usage of the functions
int main() {
    struct TreeNode* root = NULL;

    // Insertion
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);

    // Searching
    int searchKey = 40;
    if (search(root, searchKey) != NULL)
        printf("%d found in the tree.\n", searchKey);
    else
        printf("%d not found in the tree.\n", searchKey);

    // Deletion
    int deleteKey = 30;
    root = deleteNode(root, deleteKey);
    printf("%d deleted from the tree.\n", deleteKey);

    // Find the largest
    struct TreeNode* largestNode = findLargest(root);
    printf("The largest element in the tree is: %d\n", largestNode->key);

    return 0;
}

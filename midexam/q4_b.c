#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
struct Node* findInOrderSuccessor(struct Node* root, struct Node* node) {
    if (node->right != NULL) {
        return findMin(node->right);
    }
    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

int main() {
    struct Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->right->left = createNode(25);
    root->right->right = createNode(35);
    struct Node* nodeToFind = root->left;
    struct Node* successor = findInOrderSuccessor(root, nodeToFind);
    if (successor != NULL) {
        printf("In-order successor of %d is %d\n", nodeToFind->data, successor->data);
    } else {
        printf("No in-order successor found for %d\n", nodeToFind->data);
    }
    return 0;
}
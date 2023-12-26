#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int balancefactor(struct Node* root) {
    int bf = height(root->left) - height(root->right);
    return bf;
}

int RightRotate(struct Node** root) {
    struct Node* temp = (*root)->left;
    (*root)->left = temp->right;
    temp->right = (*root);
    *root = temp; // Update the root here
    return 1;
}

int LeftRotate(struct Node** root) {
    struct Node* temp = (*root)->right;
    (*root)->right = temp->left;
    temp->left = (*root);
    *root = temp; // Update the root here
    return 1;
}

int LeftBalance(struct Node** root) {
    if (balancefactor(*root) > 1 && balancefactor((*root)->left) >= 0) {
        RightRotate(root);
    } else {//left of right case
        LeftRotate(&((*root)->left));
        RightRotate(root);
    }
    return 1;
}

int RightBalance(struct Node** root) {
    if (balancefactor(*root) < -1 && balancefactor((*root)->right) <= 0) {
        LeftRotate(root);
    } else {//right of left case
        RightRotate(&((*root)->right));
        LeftRotate(root);
    }
    return 1;
}

struct Node* insert(struct Node** root, int key) {
    if (!(*root)) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = key;
        newnode->left = newnode->right = NULL;
        *root = newnode;
    } 
    else if ((*root)->data > key) {
        insert(&((*root)->left), key);
        if (balancefactor(*root) > 1) {
            LeftBalance(root);
        }
    } 
    else {
        insert(&((*root)->right), key);
        if (balancefactor(*root) < -1) {
            RightBalance(root);
        }
    }

    return *root;
}
int deleteNode(struct Node **root,int key){
        if(!(*root)){
            return 0;
        }
        else if((*root)->data > key){
            deleteNode(&((*root)->left),key);
        if (balancefactor(*root) > 1) {
            LeftBalance(root);
        }
        if (balancefactor(*root) < -1) {
            RightBalance(root);
        }
        }
        else if((*root)->data<key){
            deleteNode(&((*root)->right),key);
        if (balancefactor(*root) > 1) {
            LeftBalance(root);
        }
        if (balancefactor(*root) < -1) {
            RightBalance(root);
        } 
        }
        else{
            if((*root)->right==NULL){
                *root=(*root)->left;
                return 1;
            }
            else if((*root)->left==NULL){
                *root=(*root)->right;
                return 1;
            }
            else{
                struct Node* iptr=(*root)->left;
                while(iptr->right){
                    iptr=iptr->right;
                }
                (*root)->data=iptr->data;
                return deleteNode(&((*root)->left),(*root)->data);
              } 
        }
}


int search(struct Node **root,int key){
    if(!(*root)){
        printf("not found\n");
        return 0;
    }
    else if((*root)->data>key){
        search(&((*root)->left),key);
    }
    else if((*root)->data<key){
        search(&((*root)->right),key);
    }
    else{
        printf("found\n");
        return 1;
    }

}

int preorder(struct Node * root){
    if(root){
        
        preorder(root->left);
        printf("%d   ",root->data);
        preorder(root->right);

    }
    else{
        return 0;
    }
}

int main() {
    struct Node* root = newNode(10);
    insert(&root, 12);
    insert(&root, 14);
    insert(&root,16);
    insert(&root,18);
    printf("%d  \n", balancefactor(root));
    // printf("%d\t",root->data);
    preorder(root);
    deleteNode(&root,10);
    printf("\n%d ", balancefactor(root));
    // printf("%d\t",root->data);
    printf("\n");
    preorder(root);
    printf("\n");
    search(&root,14);
    search(&root,15);
    return 0;
}
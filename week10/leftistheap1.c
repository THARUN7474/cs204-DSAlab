#include <stdio.h>
#include <stdlib.h>
struct MaxLeftistHeapNode {
    int value;
    int npl;
    struct MaxLeftistHeapNode* left;
    struct MaxLeftistHeapNode* right;
};
struct MaxLeftistHeapNode* merge(struct MaxLeftistHeapNode* h1,struct MaxLeftistHeapNode* h2) {
    if (h1 == NULL) {
        return h2;
    }
    if (h2 == NULL) {
        return h1;
    }

    if (h1->value < h2->value) {
        struct MaxLeftistHeapNode* temp = h1;
        h1 = h2;
        h2 = temp;
    }
    h1->right = merge(h1->right, h2);
    if ((h1->left == NULL) || ((h1->right != NULL) && (h1->left->npl < h1->right->npl)) ) {
        struct MaxLeftistHeapNode* temp = h1->left;
        h1->left = h1->right;
        h1->right = temp;
    }
    if (h1->right == NULL) {
        h1->npl = 0;
    } else {
        h1->npl = h1->right->npl + 1;
    }

    return h1;
}
struct MaxLeftistHeapNode* create(int value) {
    struct MaxLeftistHeapNode* newnode = (struct MaxLeftistHeapNode*)malloc(sizeof(struct MaxLeftistHeapNode));
    newnode->value = value;
    newnode->npl = 0;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void display(struct MaxLeftistHeapNode* node){
    if(node!=0){
        printf("%d->",node->value);
        display(node->left);
        display(node->right);
    }
}
int main() {
    struct MaxLeftistHeapNode* root;
    struct MaxLeftistHeapNode* root1=NULL;
    int arr[50];
    int m;
    printf("enter the no of elements that you want:");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("enter elements in order wit space-");
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i <m; i++){
        root=create(arr[i]);
        root1=merge(root,root1);
    }
    display(root1);
    return 0;
}
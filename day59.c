#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int postIndex;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end) {
    if (start > end)
        return NULL;

    struct Node* root = newNode(postorder[postIndex--]);

    if (start == end)
        return root;

    int mid = search(inorder, start, end, root->data);

    // build right first
    root->right = buildTree(inorder, postorder, mid + 1, end);
    root->left = buildTree(inorder, postorder, start, mid - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 5;
    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    preorder(root); // Output: 1 2 4 5 3
    return 0;
}

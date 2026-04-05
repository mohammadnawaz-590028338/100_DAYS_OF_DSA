#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int preIndex = 0;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int start, int end) {
    if (start > end)
        return NULL;

    struct Node* root = newNode(preorder[preIndex++]);

    if (start == end)
        return root;

    int mid = search(inorder, start, end, root->data);

    root->left = buildTree(preorder, inorder, start, mid - 1);
    root->right = buildTree(preorder, inorder, mid + 1, end);

    return root;
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n = 5;
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};

    struct Node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root); // Output: 4 5 2 3 1
    return 0;
}

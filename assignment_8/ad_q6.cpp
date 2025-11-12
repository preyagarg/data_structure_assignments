#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to search for a value in inorder[]
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; // should never happen if input is valid
}

// Recursive helper function to build the tree
TreeNode* buildTreeHelper(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex, int n) {
    if (postIndex < 0 || inStart > inEnd)
        return NULL;

    // The current root is the last element of postorder
    TreeNode* root = new TreeNode(postorder[postIndex--]);

    // If this node has no children
    if (inStart == inEnd)
        return root;

    // Find index of root in inorder[]
    int inIndex = search(inorder, inStart, inEnd, root->val);

    // **Important:** build right subtree first (because we are going backwards in postorder)
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex, n);
    root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex, n);

    return root;
}

// Main function to construct tree
TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1; // Start from the end of postorder[]
    return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex, n);
}

// Function to print inorder traversal (for verification)
void printInorder(TreeNode* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example input
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = 5;

    TreeNode* root = buildTree(inorder, postorder, n);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

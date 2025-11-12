#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to search for an element in inorder[]
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; // should never happen if inputs are valid
}

// Recursive helper function to build the tree
TreeNode* buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex, int n) {
    if (preIndex >= n || inStart > inEnd)
        return NULL;

    // Current root is from preorder
    TreeNode* root = new TreeNode(preorder[preIndex++]);

    // If the node has no children
    if (inStart == inEnd)
        return root;

    // Find index of this root in inorder[]
    int inIndex = search(inorder, inStart, inEnd, root->val);

    // Build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex, n);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex, n);

    return root;
}

// Main function to build the tree
TreeNode* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, n - 1, preIndex, n);
}

// Function to print inorder traversal for verification
void printInorder(TreeNode* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example input
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int n = 5;

    TreeNode* root = buildTree(preorder, inorder, n);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

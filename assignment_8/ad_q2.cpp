#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to generate all BSTs from 'start' to 'end'
vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> allTrees;

    // Base case: empty subtree
    if (start > end) {
        allTrees.push_back(NULL);
        return allTrees;
    }

    // Try each number as root
    for (int i = start; i <= end; i++) {
        // Generate all left and right subtrees
        vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
        vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

        // Combine each left and right tree with root i
        for (auto left : leftTrees) {
            for (auto right : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
}

// Main function to generate BSTs for 1 to n
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesHelper(1, n);
}

// Function to print preorder traversal (for visualization)
void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> result = generateTrees(n);

    cout << "Total Unique BSTs: " << result.size() << endl;
    int count = 1;
    for (auto tree : result) {
        cout << "Tree " << count++ << ": ";
        preorder(tree);
        cout << endl;
    }

    return 0;
}

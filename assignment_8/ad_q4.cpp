#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to return right view
vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (root == NULL)
        return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (i == size - 1)
                result.push_back(node->val);

            // Push children in queue
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return result;
}

int main() {


    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> view = rightView(root);

    cout << "Right View of Binary Tree: ";
    for (int val : view)
        cout << val << " ";
    cout << endl;

    return 0;
}

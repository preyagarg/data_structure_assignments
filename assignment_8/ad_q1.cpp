#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;


    if (isLeaf(root->left))
        sum += root->left->val;
    else

        sum += sumOfLeftLeaves(root->left);

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Sum of all left leaves = " << sumOfLeftLeaves(root) << endl;

    return 0;
}

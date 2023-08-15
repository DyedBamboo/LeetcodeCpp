/**
 * @file 15.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 110 平衡二叉树
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* node) {
    if (node == nullptr)
        return 0;
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1)
        return -1;
    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    return getHeight(root) == -1 ? false : true;
}

void releaseMemory(TreeNode* root) {
    if (root == nullptr)
        return;
    releaseMemory(root->left);
    releaseMemory(root->right);
    delete root;
    root = nullptr;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    bool res = isBalanced(root);
    cout << res << endl;

    releaseMemory(root);

    return 0;
}
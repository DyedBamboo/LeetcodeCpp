/**
 * @file 19.cpp
 * @author RanZhuJun
 * @date 2023-08-23
 * @brief leetcode 112 路径之和
 *
 * @copyright RanZhuJun 2023
 *
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
        return false;
    if (!root->left && !root->right && sum == root->val) {
        return true;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

void releaseMemory(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    releaseMemory(root->left);
    releaseMemory(root->right);
    delete root;
    root = nullptr;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    int sum = 22;
    bool res = hasPathSum(root, sum);
    cout << res << endl;
    releaseMemory(root);
    return 0;
}
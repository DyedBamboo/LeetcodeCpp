/**
 * @file 17.cpp
 * @author RanZhuJun
 * @date 2023-08-23
 * @brief leetcode 404 左叶子之和
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int leftVal = 0;
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
        leftVal = root->left->val;
    }
    return leftVal + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
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
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int res = sumOfLeftLeaves(root);
    cout << res << endl;
    releaseMemory(root);
    return 0;
}
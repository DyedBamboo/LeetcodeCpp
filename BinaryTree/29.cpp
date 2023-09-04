/**
 * @file 29.cpp
 * @author RanZhuJun
 * @date 2023-09-04
 * @brief leetcode 701 二叉搜索树中的插入操作
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        TreeNode* node = new TreeNode(val);
        return node;
    }
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    if (root->val < val)
        root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 5;
    TreeNode* res = insertIntoBST(root, val);
    cout << res->val << endl;

    return 0;
}
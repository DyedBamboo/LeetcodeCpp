/**
 * @file 23.cpp
 * @author RanZhuJun
 * @date 2023-08-26
 * @brief leetcode 700 二叉树中的搜索
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    while (root != nullptr) {
        if (root->val > val)
            root = root->left;
        else if (root->val < val)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 2;
    TreeNode* res = searchBST(root, val);
    cout << res->val << endl;
    return 0;
}
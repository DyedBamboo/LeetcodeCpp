/**
 * @file 24.cpp
 * @author RanZhuJun
 * @date 2023-08-28
 * @brief leetcode 98 验证二叉搜索树
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>

using namespace std;

long long maxVal = LONG_MIN;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isVaildBST(TreeNode* root) {
    if (root == nullptr)
        return true;

    bool left = isVaildBST(root->left);
    if (maxVal < root->val)
        maxVal = root->val;
    else
        return false;

    bool right = isVaildBST(root->right);

    return left && right;
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    bool res = isVaildBST(root);
    cout << res << endl;

    return 0;
}
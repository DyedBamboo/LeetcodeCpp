/**
 * @file 28.cpp
 * @author RanZhuJun
 * @date 2023-09-04
 * @brief leetcode 235 二叉搜索树的最近公共祖先
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (root->val > p->val && root->val > q->val) {
            root = root->left;
        } else if (root->val < p->val && root->val < q->val) {
            root = root->right;
        } else
            return root;
    }
    return NULL;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* res = lowestCommonAncestor(root, p, q);
    cout << res->val << endl;

    return 0;
}
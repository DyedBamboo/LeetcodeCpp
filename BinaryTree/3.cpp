/**
 * @file 3.cpp
 * @author RanZhuJun
 * @date 2023-08-04
 * @brief leetcode 94 二叉树的中序遍历
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

/**
 * @brief 递归解法
 */
// void traversal(TreeNode* cur, vector<int>& res) {
//     if (cur == nullptr)
//         return;
//     traversal(cur->left, res);
//     res.push_back(cur->val);
//     traversal(cur->right, res);
// }

// vector<int> inorderTraversal(TreeNode* root) {
//     vector<int> res;
//     traversal(root, res);
//     return res;
// }

/**
 * @brief 迭代解法
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    if (root != nullptr)
        stk.push(root);
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        if (node != nullptr) {
            stk.pop();
            if (node->right)
                stk.push(node->right);
            stk.push(node);
            stk.push(nullptr);
            if (node->left)
                stk.push(node->left);
        } else {
            stk.pop();
            node = stk.top();
            stk.pop();
            res.push_back(node->val);
        }
    }
    return res;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = new TreeNode(vec[0]);
    root->left = new TreeNode(vec[1]);
    root->right = new TreeNode(vec[2]);
    root->left->left = new TreeNode(vec[3]);
    root->left->right = new TreeNode(vec[4]);
    root->right->left = new TreeNode(vec[5]);
    root->right->right = new TreeNode(vec[6]);
    vector<int> res = inorderTraversal(root);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
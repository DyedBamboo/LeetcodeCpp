/**
 * @file 16.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 257 二叉树的所有路径
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<string> binaryTreePaths(TreeNode* root) {
    stack<TreeNode*> treeStk;
    stack<string> pathStk;
    vector<string> result;
    if (root == nullptr)
        return result;
    treeStk.push(root);
    pathStk.push(to_string(root->val));
    while (!treeStk.empty()) {
        TreeNode* node = treeStk.top();
        treeStk.pop();
        string path = pathStk.top();
        pathStk.pop();
        if (node->left == nullptr && node->right == nullptr) {
            result.push_back(path);
        }
        if (node->right) {
            treeStk.push(node->right);
            pathStk.push(path + "->" + to_string(node->right->val));
        }

        if (node->left) {
            treeStk.push(node->left);
            pathStk.push(path + "->" + to_string(node->left->val));
        }
    }
    return result;
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> res = binaryTreePaths(root);
    for (auto str : res) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
/**
 * @file 13.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 111 二叉树的最小深度
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    queue<TreeNode*> que;
    que.push(root);
    int depth = 0;
    while (!que.empty()) {
        int size = que.size();
        depth++;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
            if (!node->left && !node->right) {
                return depth;
            }
        }
    }
    return depth;
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

    int res = minDepth(root);
    cout << res << endl;
    releaseMemory(root);

    return 0;
}
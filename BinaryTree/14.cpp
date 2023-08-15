/**
 * @file 14.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 222 完全二叉树的节点的个数
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

int countNodes(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr)
        que.push(root);
    int res = 0;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            res++;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return res;
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
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int res = countNodes(root);
    cout << res << endl;
    releaseMemory(root);

    return 0;
}
/**
 * @file 22.cpp
 * @author RanZhuJun
 * @date 2023-08-26
 * @brief leetcode 617 合并二叉树
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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr)
        return t2;
    if (t2 == nullptr)
        return t1;
    queue<TreeNode*> que;
    que.push(t1);
    que.push(t2);
    while (!que.empty()) {
        TreeNode* node1 = que.front();
        que.pop();
        TreeNode* node2 = que.front();
        que.pop();
        node1->val += node2->val;
        if(node1->left != nullptr && node2->left != nullptr) {
            que.push(node1->left);
            que.push(node2->left);
        }
        if (node1->right != nullptr && node2->right != nullptr) {
            que.push(node1->right);
            que.push(node2->right);
        }
        if (node1->left == nullptr && node2->left != nullptr) {
            node1->left = node2->left;
        }
        if (node1->right == nullptr && node2->right != nullptr) {
            node1->right = node2->right;
        }
    }
    return t1;
}

int main() {
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    TreeNode* res = mergeTrees(t1, t2);
    cout << res->val << endl;
}
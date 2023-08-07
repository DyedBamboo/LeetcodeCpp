/**
 * @file 6.cpp
 * @author RanZhuJun
 * @date 2023-08-07
 * @brief leetcode 199 二叉树的右视图
 *
 * @copyright RanZhuJun 2023
 *
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> que;
    if (root != nullptr)
        que.push(root);
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if (i == (size - 1))
                res.push_back(node->val);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return res;
}

void releaseMemory(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    releaseMemory(root->left);
    releaseMemory(root->right);
    delete root;
}

int main() {
    vector<int> vec = {1, 2, 3, NULL, 5, NULL, 4};
    TreeNode* root = new TreeNode(vec[0]);
    root->left = new TreeNode(vec[1]);
    root->right = new TreeNode(vec[2]);
    root->left->left = new TreeNode(vec[3]);
    root->left->right = new TreeNode(vec[4]);
    root->right->left = new TreeNode(vec[5]);
    root->right->right = new TreeNode(vec[6]);

    vector<int> res = rightSideView(root);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    releaseMemory(root);

    return 0;
}
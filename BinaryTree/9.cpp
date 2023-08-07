/**
 * @file 9.cpp
 * @author RanZhuJun
 * @date 2023-08-07
 * @brief leetcode 515 在每个树行中找最大值
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> largestValues(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> que;
    if (root != nullptr)
        que.push(root);
    while (!que.empty()) {
        int size = que.size();
        int max = INT_MIN;
        for (int i = 0; i < size; i++) {
            TreeNode *node = que.front();
            que.pop();
            max = std::max(max, node->val);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        res.push_back(max);
    }
    return res;
}

void releaseMemory(TreeNode *root) {
    if (root == nullptr)
        return;
    releaseMemory(root->left);
    releaseMemory(root->right);
    delete root;
    root = nullptr;
}

int main() {
    vector<int> vec = {1, 3, 2, 5, 3, NULL, 9};
    TreeNode *root = new TreeNode(vec[0]);
    root->left = new TreeNode(vec[1]);
    root->right = new TreeNode(vec[2]);
    root->left->left = new TreeNode(vec[3]);
    root->left->right = new TreeNode(vec[4]);
    root->right->right = new TreeNode(vec[6]);
    vector<int> res = largestValues(root);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    releaseMemory(root);
    return 0;
}
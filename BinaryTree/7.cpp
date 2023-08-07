/**
 * @file 7.cpp
 * @author RanZhuJun
 * @date 2023-08-07
 * @brief leetcode 637 二叉树的层平均值
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

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    queue<TreeNode*> que;
    if (root != nullptr)
        que.push(root);
    while (!que.empty()) {
        int size = que.size();
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            sum += node->val;
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        double average_num = sum / size;
        res.push_back(average_num);
    }
    return res;
}

void releaseMemory(TreeNode* root) {
    if (root == nullptr)
        return;
    releaseMemory(root->left);
    releaseMemory(root->right);
    delete root;
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

    vector<double> res = averageOfLevels(root);

    for (auto num : res) {
        cout << num << endl;
    }

    return 0;
}
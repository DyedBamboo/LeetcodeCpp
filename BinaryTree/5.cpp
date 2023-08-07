/**
 * @file 5.cpp
 * @author RanZhuJun
 * @date 2023-08-07
 * @brief leetcode 107 二叉树的层序遍历Ⅱ
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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if (root != nullptr)
        que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        res.push_back(vec);
    }
    reverse(res.begin(), res.end());
    return res;
}

/**
 * @brief 手动释放内存
 *
 * @param root
 */
void releaseMemory(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
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

    vector<vector<int>> res = levelOrder2(root);
    for (auto vec : res) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
    releaseMemory(root);
    return 0;
}
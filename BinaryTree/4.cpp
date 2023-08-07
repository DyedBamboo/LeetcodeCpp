/**
 * @file 4.cpp
 * @author RanZhuJun
 * @date 2023-08-07
 * @brief leetcode 102 二叉树的层序遍历
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

/**
 * @brief 递归解法
 *
 * @param root
 * @return vector<vector<int>>
 */
// void order(TreeNode* cur, vector<vector<int>>& res, int depth) {
//     if (cur == nullptr)
//         return;
//     if (res.size() == depth)
//         res.push_back(vector<int>());
//     res[depth].push_back(cur->val);
//     order(cur->left, res, depth + 1);
//     order(cur->right, res, depth + 1);
// }

// vector<vector<int>> levelOrder(TreeNode* root) {
//     vector<vector<int>> res;
//     int depth = 0;
//     order(root, res, depth);
//     return res;
// }

/**
 * @brief 迭代解法
 *
 * @param root
 * @return vector<vector<int>>
 */
vector<vector<int>> levelOrder(TreeNode* root) {
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
    vector<vector<int>> res = levelOrder(root);
    for (auto vec : res) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
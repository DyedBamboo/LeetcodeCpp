/**
 * @file 26.cpp
 * @author RanZhuJun
 * @date 2023-08-28
 * @brief leetcode 501 二叉搜索树中的众数
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

vector<int> findMode(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    int maxCount = 0;
    int count = 0;
    vector<int> res;
    while (cur != nullptr || !stk.empty()) {
        if (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            stk.pop();
            if (pre == nullptr) {
                count = 1;
            } else if (pre->val == cur->val) {
                count++;
            } else {
                count = 1;
            }
            if (count == maxCount) {
                res.push_back(cur->val);
            }
            if (count > maxCount) {
                maxCount = count;
                res.clear();
                res.push_back(cur->val);
            }
            pre = cur;
            cur = cur->right;
        }
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    vector<int> res = findMode(root);
    for (auto num : res) {
        cout << num << endl;
    }
    return 0;
}
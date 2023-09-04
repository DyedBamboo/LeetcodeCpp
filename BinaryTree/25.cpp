/**
 * @file 25.cpp
 * @author RanZhuJun
 * @date 2023-08-28
 * @brief leetcode 530 二叉搜索树的最小绝对差
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getMinimumDifference(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    TreeNode* pre = nullptr;
    int res = INT_MAX;
    while (cur != nullptr || !stk.empty()) {
        if (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            stk.pop();
            if (pre != nullptr) {
                res = min(res, cur->val - pre->val);
            }
            pre = cur;
            cur = cur->right;
        }
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    int res = getMinimumDifference(root);

    cout << res << endl;

    return 0;
}
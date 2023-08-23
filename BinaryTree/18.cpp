/**
 * @file 18.cpp
 * @author RanZhuJun
 * @date 2023-08-23
 * @brief leetcode 513 找树左下角的值
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

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> que;
    if(root != nullptr) {
        que.push(root);
    }
    int res = 0;
    while(!que.empty()) {
        int size = que.size();
        for(int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if(i == 0) res = node->val;
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
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
    root = nullptr;
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    int res = findBottomLeftValue(root);
    cout << res << endl;
    releaseMemory(root);
    return 0;
}
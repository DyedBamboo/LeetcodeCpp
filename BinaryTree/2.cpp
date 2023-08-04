/***
 * @Author: RanZhuJun
 * @Date: 2023-08-04 10:01:25
 * @LastEditTime: 2023-08-04 10:01:25
 * @Description: leetcode 145 二叉树的后序遍历
 * @FilePath: \LeetcodeCpp\BinaryTree\2.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void traversal(TreeNode* cur, vector<int>& res) {
    if (cur == nullptr) return;
    traversal(cur->left, res);
    traversal(cur->right, res);
    res.push_back(cur->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    traversal(root, res);
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
    vector<int> res = postorderTraversal(root);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
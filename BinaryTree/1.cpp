/***
 * @Author: RanZhuJun
 * @Date: 2023-08-04 00:11:46
 * @LastEditTime: 2023-08-04 00:11:55
 * @Description: leetcode 144 二叉树的前序遍历
 * @FilePath: \LeetcodeCpp\BinaryTree\2.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> traversal(TreeNode* cur, vector<int> vec) {
    if (cur == nullptr) {
        return vec;
    }
    vec.push_back(cur->val);
    vec = traversal(cur->left, vec);
    vec = traversal(cur->right, vec);
    return vec;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    vec = traversal(root, vec);
    return vec;
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
    vector<int> res = preorderTraversal(root);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
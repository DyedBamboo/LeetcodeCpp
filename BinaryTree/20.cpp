/**
 * @file 20.cpp
 * @author RanZhuJun
 * @date 2023-08-23
 * @brief leetcode 106 从中序遍历与后序遍历序列构造出二叉树
 *
 * @copyright RanZhuJun 2023
 *
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

TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
    // 如果数组为空，说明是空节点
    if (postorder.size() == 0)
        return nullptr;
    // 后序遍历数组最后一个元素，就是当前的中间节点
    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);

    // 叶子节点
    if (postorder.size() == 1)
        return root;

    // 寻找中序遍历的切割点
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue)
            break;
    }

    // 切割中序数组
    // 左闭右开区间，[0,delimiterIndex)
    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    // [delimiterIndex+1,end)
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());

    // postorder舍弃末尾元素
    postorder.resize(postorder.size() - 1);

    // 切割后序数组
    // 依然左闭右开，注意这里使用了左中序数组的大小作为切割点
    // [0，leftInorder.size())
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    // [leftInorder.size(),end)
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

    root->left = traversal(leftInorder, leftPostorder);
    root->right = traversal(rightInorder, rightPostorder);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0 || postorder.size() == 0)
        return nullptr;
    return traversal(inorder, postorder);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = buildTree(inorder, postorder);
    cout << root->val << endl;
    return 0;
}
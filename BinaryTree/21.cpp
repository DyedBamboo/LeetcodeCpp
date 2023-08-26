/**
 * @file 21.cpp
 * @author RanZhuJun
 * @date 2023-08-26
 * @brief leetcode 654 最大二叉树
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

TreeNode* traversal(vector<int>& nums, int left, int right) {
    if (left >= right)
        return nullptr;
    int maxValueIndex = left;
    for (int i = left + 1; i < right; ++i) {
        if (nums[i] > nums[maxValueIndex]) {
            maxValueIndex = i;
        }
    }

    TreeNode* root = new TreeNode(nums[maxValueIndex]);
    root->left = traversal(nums, left, maxValueIndex);
    root->right = traversal(nums, maxValueIndex + 1, right);

    return root;
}

TreeNode* constructMaximumBinarryTree(vector<int>& nums) {
    return traversal(nums, 0, nums.size());
}

int main() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode* root = constructMaximumBinarryTree(nums);
    cout << root->val << endl;
}
/**
 * @file 8.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 416 分割等和子集
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    // dp[i] 中的i表示背包内总和
    // dp[i] 表示背包内总和为i时，能否恰好装满
    // 题目中说：每个数组中的元素不会超过100，数组的大小不会超过200
    // 所以背包的总和不会超过20000，背包最大只需要其中一半，所以10001大小就可以了
    vector<int> dp(10001, 0);
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    // 如果总和为奇数，那么肯定不能分割成两个和相等的子集
    if (sum % 2 == 1) {
        return false;
    }
    // 背包的总和为sum的一半
    int target = sum / 2;

    // 开始01背包
    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    // 集合中的元素能否恰好装满背包
    if (dp[target] == target) {
        return true;
    } else {
        return false;
    }
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    bool res = canPartition(nums);
    cout << res << endl;
    return 0;
}
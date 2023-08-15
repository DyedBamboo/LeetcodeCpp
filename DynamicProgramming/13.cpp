/**
 * @file 13.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 组合总数IV
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= target; ++i) {          // 遍历背包
        for (int j = 0; j < nums.size(); ++j) {  // 遍历物品
            if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int res = combinationSum4(nums, target);

    cout << res << endl;

    return 0;
}
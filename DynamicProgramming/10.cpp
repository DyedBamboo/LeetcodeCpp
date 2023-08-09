/**
 * @file 10.cpp
 * @author RanZhuJun
 * @date 2023-08-09
 * @brief leetcode 494 目标和
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (abs(target) > sum)
        return 0;
    if ((target + sum) % 2 == 1)
        return 0;
    int bagSize = (target + sum) / 2;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = target; j >= nums[i]; --j) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[bagSize];
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int res = findTargetSumWays(nums, target);
    cout << res << endl;

    return 0;
}
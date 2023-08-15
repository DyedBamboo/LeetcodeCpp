/**
 * @file 15.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 322 零钱兑换
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);  // dp[j]: 凑足总数为j所需的最少的钱币的个数为dp[j]，递推公式中取最小值，所以初始化为INT_MAX便于更新覆盖
    dp[0] = 0;                            // 凑足总数为0所需的最少钱币个数为0
    for (int i = 0; i <= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                /*
                    递推公式：凑足总额为 i - coins[j]的最少个数为dp[i - coins[j]],那么只需要
                    加上一个钱币coins[j]即dp[i - coins[j]] + 1就是dp[i]
                */
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);  // 递推公式
            }
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int res = coinChange(coins, amount);
    cout << res << endl;

    return 0;
}
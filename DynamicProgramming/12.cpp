/**
 * @file 12.cpp
 * @author RanZhuJun
 * @date 2023-08-09
 * @brief leetcode 518 零钱兑换II
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);  // dp[j]:装满容量为j的背包最多有dp[j]种方法
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
        for (int j = coins[i]; j <= amount; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int res = change(amount, coins);
    cout << res << endl;
}
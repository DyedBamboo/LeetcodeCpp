/**
 * @file 14.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 70 爬楼梯
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main() {
    int n = 2;
    int res = climbStairs(n);
    cout << res << endl;
}
/**
 * @file 6.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 343 整数拆分
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i < n + 1; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        }
    }
    return dp[n];
}

int main() {
    int n = 10;
    int res = integerBreak(n);
    cout << res << endl;
}
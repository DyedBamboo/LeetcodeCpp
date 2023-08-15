/**
 * @file 16.cpp
 * @author RanZhuJun
 * @date 2023-08-15
 * @brief leetcode 279 完全平方数
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int numSquare(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }
    return dp[n];
}

int main() {
    int n = 12;
    int res = numSquare(n);
    cout << res << endl;
    return 0;
}
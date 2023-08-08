/**
 * @file 4.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 62 不同路径
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m + 1; ++i) {
        dp[i][1] = 1;
    }
    for (int j = 0; j < n + 1; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i < m + 1; ++i) {
        for (int j = 2; j < n + 1; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

int main() {
    int m = 3, n = 7;
    int res = uniquePaths(m, n);
    cout << res << endl;
}
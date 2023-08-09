/**
 * @file 11.cpp
 * @author RanZhuJun
 * @date 2023-08-09
 * @brief leetcode 474 一和零
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string str : strs) {
        int oneNum = 0, zeroNum = 0;
        for (char c : str) {
            if (c == '0')
                zeroNum++;
            else
                oneNum++;
        }
        for (int i = m; i >= zeroNum; i--) {
            for (int j = n; j >= oneNum; j--) {
                dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<string> strs = {"10", "0001", "11101", "1", "0"};
    int m = 5;
    int n = 4;
    int res = findMaxForm(strs, m, n);
    cout << res << endl;
    return 0;
}
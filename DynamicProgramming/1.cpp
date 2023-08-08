/**
 * @file 1.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 509 斐波那契数
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    if (n < 2) {
        return n;
    }
    vector<int> dp(n + 1);              // dp[i]表示第i个斐波那契数
    dp[0] = 0;                          // 初始化dp数组
    dp[1] = 1;                          // 初始化dp数组
    for (int i = 2; i < n + 1; i++) {   // 从2开始遍历
        dp[i] = dp[i - 1] + dp[i - 2];  // 状态转移方程
    }

    return dp[n];
}

int main() {
    int n = 3;
    int res = fib(n);
    cout << res << endl;
    return 0;
}
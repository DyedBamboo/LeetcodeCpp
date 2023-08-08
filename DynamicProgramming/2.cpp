/**
 * @file 2.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 70 爬楼梯
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n < 2) {
        return n;
    }
    vector<int> dp(n + 1);              // dp[i]表示爬到第i层楼梯的方法数
    dp[1] = 1;                          // 初始化dp数组
    dp[2] = 2;                          // 初始化dp数组
    for (int i = 3; i < n + 1; i++) {   // 从2开始遍历
        dp[i] = dp[i - 1] + dp[i - 2];  // 状态转移方程
    }

    return dp[n];
}

int main() {
    int n = 3;
    int res = climbStairs(n);
    cout << res << endl;
    return 0;
}

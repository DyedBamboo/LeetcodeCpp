/**
 * @file 7.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 96 不同的二叉搜索树
 * 
 * @copyright RanZhuJun 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1);  // dp[i]表示i个节点的二叉搜索树的个数
    dp[0] = 1;              // 初始化dp数组
    dp[1] = 1;              // 初始化dp数组
    for (int i = 2; i < n + 1; i++) {  // 从2开始遍历
        for (int j = 1; j < i + 1; j++) {  // 从1开始遍历
            dp[i] += dp[j - 1] * dp[i - j];  // 状态转移方程
        }
    }

    return dp[n];
}

int main() {
    int n = 3;
    int res = numTrees(n);
    cout << res << endl;
    return 0;
}
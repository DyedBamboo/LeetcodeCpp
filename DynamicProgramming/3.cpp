/**
 * @file 3.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 746 使用最小花费爬楼梯
 * 
 * @copyright RanZhuJun 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < n + 1; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[n];
}

int main() {
    vector<int> cost = {10, 15, 20};
    int res = minCostClimbingStairs(cost);
    cout << res << endl;
    return 0;
}
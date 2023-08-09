/**
 * @file 9.cpp
 * @author RanZhuJun
 * @date 2023-08-09
 * @brief leetcode 1049 最后一块石头的重量II
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int i = 0; i < stones.size(); ++i) {
        sum += stones[i];
    }
    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    for(int i = 0; i < stones.size(); ++i) {
        for(int j = target; j >= stones[i];j--) {
            dp[j] = max(dp[j],dp[j - stones[i]] + stones[i]);
        }
    }
    return sum - dp[target] * 2;
}

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int res = lastStoneWeightII(stones);
    cout << res << endl;
    return 0;
}
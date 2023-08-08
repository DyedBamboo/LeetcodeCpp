/**
 * @file 5.cpp
 * @author RanZhuJun
 * @date 2023-08-08
 * @brief leetcode 63 不同路径 II
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int unqiuePathWithObstacles(vector<vector<int>> obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {  // 判断终点和起始点是否有障碍物
        return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1)
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    int res = unqiuePathWithObstacles(obstacleGrid);
    cout << res << endl;
    return 0;
}
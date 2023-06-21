/***
 * @Author: RanZhuJun
 * @Date: 2023-06-21 17:18:47
 * @LastEditTime: 2023-06-21 17:18:52
 * @Description: leetcode 59 螺旋矩阵II
 * @FilePath: \Cpp\Array\5.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    int left = 0, right = n - 1;
    int top = 0, button = n - 1;
    int num = 1, toltal_num = n * n;
    while(num <= toltal_num) {
        for(int i = left; i <= right; i++) {res[top][i] = num++;} top++;
        for(int i = top; i <= button; i++) {res[i][right] = num++;} right--;
        for(int i = right; i >= left; i--) {res[button][i] = num++;} button--;
        for(int i = button; i >= top; i--) {res[i][left] = num++;} left++; 
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = generateMatrix(n);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
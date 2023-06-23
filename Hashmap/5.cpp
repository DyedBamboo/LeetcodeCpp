/***
 * @Author: RanZhuJun
 * @Date: 2023-06-23 11:15:10
 * @LastEditTime: 2023-06-23 11:15:16
 * @Description: Leetcode 454 四数相加II
 * @FilePath: \LeetcodeCpp\Hashmap\5.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> map;  // A,B数组之和，出现的次数
    int sum = 0;
    for (int num1 : A) {
        for (int num2 : B) {
            sum = num1 + num2;
            map[sum]++;
        }
    }
    int res = 0;
    for (int num3 : C) {
        for (int num4 : D) {
            if (map.find(0 - num3 - num4) != map.end()) {
                res += map[0 - num3 - num4];
            }
        }
    }
    return res;
}

int main() {
    vector<int> A{1, 2};
    vector<int> B{-2, -1};
    vector<int> C{-1, 2};
    vector<int> D{0, 2};
    int res = fourSumCount(A, B, C, D);
    cout << res << endl;
}

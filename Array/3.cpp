/***
 * @Author: RanZhuJun
 * @Date: 2023-06-21 16:19:19
 * @LastEditTime: 2023-06-21 16:22:40
 * @Description: leetcode 997 有序数组的平方
 * @FilePath: \Cpp\Array\3.cpp
 * @版权声明 RanZhuJun
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// vector<int> sortedSquares(vector<int> &nums)
// {
//     vector<int> res;
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         nums[i] *= nums[i];
//     }
//     sort(nums.begin(), nums.end());
//     res = nums;
//     return res;
// }

vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size() - 1;
    vector<int> res(nums.size(), 0);
    for(int i = 0, j = nums.size() - 1; i <= j;) {
        if(nums[i] * nums[i] < nums[j] * nums[j]) {
            res[n--] = nums[j] * nums[j];
            j--;
        }else {
            res[n--] = nums[i] * nums[i];
            i++;
        }
    }
    return res;
}

int main() {
    vector<int> nums{-4, -1, 0, 3, 10};
    vector<int> res;
    res = sortedSquares(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}

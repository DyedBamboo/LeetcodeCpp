/***
 * @Author: RanZhuJun
 * @Date: 2023-06-21 16:04:19
 * @LastEditTime: 2023-06-21 16:07:03
 * @Description:Leetcode 27 移除元素
 * @FilePath: \Cpp\Array\2.cpp
 * @版权声明 RanZhuJun
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> nums = {3,2,2,3};
    int val = 3;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        if (nums[left] == val) {
            swap(nums[left], nums[right]);
            right--;
        } else {
            left++;
        }
    }
    cout << left << endl;
}
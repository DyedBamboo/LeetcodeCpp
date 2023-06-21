/***
 * @Author: RanZhuJun
 * @Date: 2023-06-21 16:59:47
 * @LastEditTime: 2023-06-21 16:59:52
 * @Description: 长度最小的子数组
 * @FilePath: \Cpp\Array\4.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int res = INT_MAX;
    int subLength = 0;
    for (int right = 0; right < n; ++right) {
        sum += nums[right];
        while (sum >= target) {
            subLength = right - left + 1;
            res = res < subLength ? res : subLength;
            sum -= nums[left++];
        }
    }

    return res;
}

int main() {
    int s = 7;
    vector<int> nums{2, 3, 1, 2, 4, 3};
    int length = minSubArrayLen(s, nums);
    cout << length << endl;
}

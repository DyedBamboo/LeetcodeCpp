/***
 * @Author: RanZhuJun
 * @Date: 2023-07-12 19:37:09
 * @LastEditTime: 2023-07-12 19:37:15
 * @Description: leetcode 18 四数之和
 * @FilePath: \LeetcodeCpp\DoublePointer\10.cpp
 * @版权声明 RanZhuJun
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> FourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++, right--;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = FourSum(nums, target);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
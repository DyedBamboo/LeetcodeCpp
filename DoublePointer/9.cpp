/***
 * @Author: RanZhuJun
 * @Date: 2023-07-12 19:29:04
 * @LastEditTime: 2023-07-12 19:29:09
 * @Description: leetcode 15 三数之和
 * @FilePath: \LeetcodeCpp\DoublePointer\9.cpp
 * @版权声明 RanZhuJun
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            return result;
        }

        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;

                right--;
                left++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = threeSum(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }

    return 0;
}
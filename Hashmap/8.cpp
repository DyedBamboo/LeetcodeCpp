/***
 * @Author: RanZhuJun
 * @Date: 2023-06-23 16:22:30
 * @LastEditTime: 2023-06-23 16:22:47
 * @Description: leetcode 18 四数之和
 * @FilePath: \LeetcodeCpp\Hashmap\8.cpp
 * @版权声明 RanZhuJun
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > target && nums[i] >= 0) {
            break;
        }
        if (nums[i] == nums[i - 1] && i > 0) {
            continue;
        }
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                break;
            }

            if (nums[j] == nums[j - 1] && j >= i + 1) {
                continue;
            }

            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                    right--;
                } else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                    left++;
                } else {
                    res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;
                }
            }
        }
    }
    return res;
}
int main() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    for (auto it : res) {
        for (int num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
}
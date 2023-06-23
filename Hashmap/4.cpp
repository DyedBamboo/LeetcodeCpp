/***
 * @Author: RanZhuJun
 * @Date: 2023-06-23 10:49:37
 * @LastEditTime: 2023-06-23 10:49:43
 * @Description: leetcode 1 两数之和
 * @FilePath: \LeetcodeCpp\Hashmap\4.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // key:数组元素， value:数组元素下标
    for (int i = 0; i < nums.size(); ++i) {
        auto iter = map.find(target - nums[i]);
        if (iter != map.end()) {
            return {iter->second, i};
        }
        map.insert(pair<int, int>(nums[i], i));
    }
    return {};
}

int main() {
    int target = 9;
    vector<int> nums{2, 7, 11, 15};
    vector<int> res = twoSum(nums, target);
    cout << res[0] << " " << res[1] << endl;
}
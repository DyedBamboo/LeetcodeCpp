/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 22:39:27
 * @LastEditTime: 2023-06-22 22:48:18
 * @Description:Leetcode 349. 两个数组的交集
 * @FilePath: \LeetcodeCpp\Hashmap\2.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> map;
    for(int num : nums1) {
        map[num]++;
    }
    unordered_set<int> ans;
    for(int num : nums2) {
        if(map[num] != 0) {
            ans.insert(num);
        }else {
            continue;
        }
    }
    return vector<int>(ans.begin(),ans.end());
}

int main() {
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    vector<int> res = intersection(nums1, nums2);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
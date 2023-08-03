/***
 * @Author: RanZhuJun
 * @Date: 2023-08-03 23:59:45
 * @LastEditTime: 2023-08-04 00:04:10
 * @Description: leetcode 347 前 K 个高频元素
 * @FilePath: \LeetcodeCpp\StackAndQueue\8.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int num : nums) {
        map[num]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto it = map.begin(); it != map.end(); it++) {
        pq.push(make_pair(it->second, it->first));
    }
    vector<int> res;
    while (k > 0) {
        res.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
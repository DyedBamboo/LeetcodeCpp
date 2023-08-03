/***
 * @Author: RanZhuJun
 * @Date: 2023-08-03 23:42:16
 * @LastEditTime: 2023-08-03 23:42:17
 * @Description: leetcode 239 滑动窗口最大值
 * @FilePath: \LeetcodeCpp\StackAndQueue\7.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res; // 存放结果
    if (nums.empty()) // 判断数组是否为空
        return res;
    deque<int> q; // 双端队列
    for (int i = 0; i < nums.size(); i++) {// 遍历数组
        if (!q.empty() && q.front() == i - k) // 判断队首元素是否过期
            q.pop_front();// 过期则弹出
        while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();// 判断队尾元素是否小于当前元素，小于则弹出
        q.push_back(i);// 将当前元素下标加入队列
        if (i >= k - 1) // 判断是否满足窗口大小
            res.push_back(nums[q.front()]); // 将队首元素加入结果数组
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
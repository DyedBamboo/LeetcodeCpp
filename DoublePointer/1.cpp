/***
 * @Author: RanZhuJun
 * @Date: 2023-06-29 20:23:36
 * @LastEditTime: 2023-06-29 20:23:41
 * @Description: leetcode 27. 移除元素
 * @FilePath: \LeetcodeCpp\DoublePointer\1.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] != val) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main() {
    vector<int> nums{3, 2, 2, 3};
    int val = 3;
    int res = removeElement(nums, val);
    cout << res << endl;
    return 0;
}
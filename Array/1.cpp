/*** 
 * @Author: RanZhuJun
 * @Date: 2023-06-21 16:01:49
 * @LastEditTime: 2023-06-21 16:01:49
 * @Description: 
 * @FilePath: \Cpp\Array\704BinarySearch.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int left = 0;
    int right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            cout << mid << endl;
            return 0;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid -1;
        }
    }
    cout << -1 << endl;
    return 0;
}
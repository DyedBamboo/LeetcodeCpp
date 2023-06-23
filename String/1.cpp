/***
 * @Author: RanZhuJun
 * @Date: 2023-06-23 16:50:04
 * @LastEditTime: 2023-06-23 16:51:15
 * @Description: leetcode 344 反转字符串
 * @FilePath: \LeetcodeCpp\String\1.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while(left < right) {
        swap(s[right],s[left]);
        right--;
        left++;
    }
}

int main() {
    vector<char> s{'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
}
/***
 * @Author: RanZhuJun
 * @Date: 2023-06-23 17:04:32
 * @LastEditTime: 2023-06-23 17:04:43
 * @Description: 反转字符串II
 * @FilePath: \LeetcodeCpp\String\2.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>

using namespace std;

void reverse(string& s, int left, int right) {
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

string reverseString(string s, int k) {
    string ans;
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k) {
        if (i + k <= s.size()) {
            reverse(s, i, i + k - 1);
            continue;
        }
        reverse(s, i, s.size() - 1);
    }
    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;
    string ans = reverseString(s, k);
    cout << ans << endl;
}
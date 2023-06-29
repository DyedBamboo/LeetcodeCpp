/***
 * @Author: RanZhuJun
 * @Date: 2023-06-29 20:32:12
 * @LastEditTime: 2023-06-29 20:32:12
 * @Description: leetcode 344.反转字符串
 * @FilePath: \LeetcodeCpp\DoublePointer\2.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

int main() {
    vector<char> s{'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (auto ch : s) {
        cout << ch;
    }
    cout << endl;
}
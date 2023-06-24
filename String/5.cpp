/***
 * @Author: RanZhuJun
 * @Date: 2023-06-24 13:06:44
 * @LastEditTime: 2023-06-24 13:06:49
 * @Description: 剑指Offer58-II.左旋转字符串
 * @FilePath: \LeetcodeCpp\String\5.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseLeftWords(string s, int n) {
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s{"abcdefg"};
    int n = 2;
    string res = reverseLeftWords(s, n);
    cout << res << endl;
}

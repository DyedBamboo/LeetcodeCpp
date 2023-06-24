/***
 * @Author: RanZhuJun
 * @Date: 2023-06-24 12:14:17
 * @LastEditTime: 2023-06-24 12:14:22
 * @Description: leetcode 151.翻转字符串里的单词
 * @FilePath: \LeetcodeCpp\String\4.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s) {
    string res;
    int i = s.size() - 1, j = i;
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;
        j = i;
        if (i < 0) break;
        while (i >= 0 && s[i] != ' ') i--;
        if (res.size() == 0)
            res = s.substr(i + 1, j - i);
        else
            res = res + " " + s.substr(i + 1, j - i);
    }
    return res;
}

int main() {
    string s = "the sky is blue";
    string res = reverseWords(s);
    cout << res << endl;
    return 0;
}
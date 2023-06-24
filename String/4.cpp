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

void reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
        swap(s[i], s[j]);
    }
}

void removeExtraSpaces(string& s) {
    int slow = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            if (slow != 0)
                s[slow++] = ' ';
        }
        while (i < s.size() && s[i] != ' ') {
            s[slow++] = s[i++];
        }
    }
    s.resize(slow);
}

string reverseWords(string s) {
    removeExtraSpaces(s);
    reverse(s, 0, s.size() - 1);
    int start = 0;
    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == ' ') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}

int main() {
    string s = "the sky is blue";
    string res = reverseWords(s);
    cout << res << endl;
    return 0;
}
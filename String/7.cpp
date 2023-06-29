/***
 * @Author: RanZhuJun
 * @Date: 2023-06-24 16:17:37
 * @LastEditTime: 2023-06-24 16:17:42
 * @Description: leetcode 459.重复的子字符串
 * @FilePath: \LeetcodeCpp\String\7.cpp
 * @版权声明 RanZhuJun
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

void getNext(int* next, const std::string& s) {
    next[0] = 0;
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

bool repeatedSubstringPattern(std::string s) {
    if (s.size() == 0) {
        return false;
    }

    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0) {
        return true;
    }
    return false;
}

int main() {
    std::string s{"abcabc"};
    bool res = repeatedSubstringPattern(s);
    std::cout << res << std::endl;
}
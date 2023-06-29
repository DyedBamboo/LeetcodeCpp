/***
 * @Author: RanZhuJun
 * @Date: 2023-06-24 13:22:51
 * @LastEditTime: 2023-06-24 13:22:55
 * @Description: leetcode 28. 实现 strStr()
 * @FilePath: \LeetcodeCpp\String\6.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>

using namespace std;

void getNext(int* next, const string& s) {
    int j = 0; // 初始化
    next[0] = 0; //初始化
    for(int i = 1; i < s.size(); i++) { //注意遍历是从下标1开始，注意循环是while循环
        while(j > 0 && s[i] != s[j]) { // 处理前后缀不同的情况
            j = next[j - 1];
        }
        if(s[i] == s[j]) { //处理前后缀相同的情况
            j++;
        }
        next[i] = j;
    }
}


int strStr(string haystack, string needle) {
    if(needle.size() == 0) {
        return 0;
    }
    int next[needle.size()];
    getNext(next,needle); // 获得模式串的next数组
    int j = 0;//模式串开始匹配的位置，即next数组中的索引
    for(int i = 0; i < haystack.size(); ++i) { //遍历文本串
        while(j > 0 && haystack[i] != haystack[j]) { //不匹配，注意是while循环
            j = next[j - 1]; //寻找匹配之前的位置
        }
        if(haystack[i] == needle[j]) {//匹配，i 和 j 同时向后移动
            j++;//i的增加在for循环里
        }
        if(j == needle.size()) {//文本串里出现了模式串
            return (i - needle.size() + 1);
        }
    }
    return -1;
}

int main() {
    string haystack{"hello"};
    string needle{"ll"};
    int res = strStr(haystack, needle);
    cout << res << endl;
}
/***
 * @Author: RanZhuJun
 * @Date: 2023-06-24 12:06:55
 * @LastEditTime: 2023-06-24 12:07:00
 * @Description: 剑指Offer 05.替换空格
 * @FilePath: \LeetcodeCpp\String\3.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string s) {
    string res;
    for (auto c : s) {
        if (c == ' ')
            res += "%20";
        else
            res += c;
    }
    return res;
}

int main() {
    string s = "We are happy.";
    string res = replaceSpace(s);
    cout << res << endl;
    return 0;
}
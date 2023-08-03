/***
 * @Author: RanZhuJun
 * @Date: 2023-08-03 23:24:50
 * @LastEditTime: 2023-08-03 23:25:10
 * @Description: leetcode 1047 1047. 删除字符串中的所有相邻重复项
 * @FilePath: \LeetcodeCpp\StackAndQueue\5.cpp
 * @版权声明 RanZhuJun
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    stack<char> stk;
    for (char ch : s) {
        if (!stk.empty() && stk.top() == ch) {
            stk.pop();
        } else {
            stk.push(ch);
        }
    }

    string res;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;

    return 0;
}
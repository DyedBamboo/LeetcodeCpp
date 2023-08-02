/***
 * @Author: RanZhuJun
 * @Date: 2023-08-02 17:30:10
 * @LastEditTime: 2023-08-02 17:38:56
 * @Description:leetcode 20 有效的括号
 * @FilePath: \LeetcodeCpp\StackAndQueue\4.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    int size = s.size();
    if (size % 2 == 1) {
        return false;
    }
    stack<char> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            stk.push(')');
        else if (s[i] == '[')
            stk.push(']');
        else if (s[i] == '{')
            stk.push('}');
        else if (stk.empty() || stk.top() != s[i])
            return false;
        else
            stk.pop();
    }
    return stk.empty();
}

int main() {
    string s = "()[]{}";
    cout << isValid(s) << endl;
    s = "()[";
    cout << isValid(s) << endl;
    return 0;
}
/***
 * @Author: RanZhuJun
 * @Date: 2023-08-03 23:32:33
 * @LastEditTime: 2023-08-03 23:32:43
 * @Description: leetcode 150. 逆波兰表达式求值
 * @FilePath: \LeetcodeCpp\StackAndQueue\6.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            if (token == "+") {
                stk.push(num2 + num1);
            } else if (token == "-") {
                stk.push(num2 - num1);
            } else if (token == "*") {
                stk.push(num2 * num1);
            } else {
                stk.push(num2 / num1);
            }
        } else {
            stk.push(atoi(token.c_str()));
        }
    }
    return stk.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens) << endl;
    return 0;
}
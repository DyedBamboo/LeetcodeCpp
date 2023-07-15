/***
 * @Author: RanZhuJun
 * @Date: 2023-07-15 21:42:53
 * @LastEditTime: 2023-07-15 21:43:03
 * @Description: leetcode 232.用栈实现队列
 * @FilePath: \LeetcodeCpp\StackAndQueue\1.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {
    }

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }

    int peek() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    return 0;
}
/***
 * @Author: RanZhuJun
 * @Date: 2023-07-15 21:51:38
 * @LastEditTime: 2023-07-15 21:51:38
 * @Description: leetcode 225 用队列实现栈
 * @FilePath: \LeetcodeCpp\StackAndQueue\2.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
    return 0;
}
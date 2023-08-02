/***
 * @Author: RanZhuJun
 * @Date: 2023-08-02 17:19:53
 * @LastEditTime: 2023-08-02 17:19:53
 * @Description: leetcode 225 用队列实现栈
 * @FilePath: \LeetcodeCpp\StackAndQueue\3.cpp
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
        q1.push(x);
    }

    int pop() {
        int size = q1.size();
        size--;
        while (size--) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        q1 = q2;
        while (!q2.empty()) {
            q2.pop();
        }
        return res;
    }

    int top() {
        return q1.back();
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
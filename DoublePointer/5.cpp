/***
 * @Author: RanZhuJun
 * @Date: 2023-07-03 18:42:06
 * @LastEditTime: 2023-07-03 18:42:15
 * @Description: leetcode 206.反转链表
 * @FilePath: \LeetcodeCpp\DoublePointer\5.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>

using namespace std;

struct LinkNode {
    int val;
    LinkNode* next;
    LinkNode(int val) : val(val), next(nullptr) {}
};

LinkNode* reverseList(LinkNode* head) {
    LinkNode* temp;
    LinkNode* cur = head;
    LinkNode* pre = nullptr;
    while (cur) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

int main() {
    LinkNode* head = new LinkNode(1);
    LinkNode* cur = head;
    for (int i = 2; i <= 5; ++i) {
        LinkNode* newNode = new LinkNode(i);
        cur->next = newNode;
        cur = newNode;
    }
    LinkNode* res = reverseList(head);
    while (res != nullptr) {
        cout << res->val << " ";
        LinkNode* temp = res;
        res = res->next;
        delete temp;
    }
    cout << endl;

    return 0;
}
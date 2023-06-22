/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 02:14:26
 * @LastEditTime: 2023-06-22 02:14:32
 * @Description: 面试题 02.07. 链表相交
 * @FilePath: \LeetcodeCpp\List\7.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    while (curA != curB) {
        curA = curA == nullptr ? headB : curA->next;
        curB = curB == nullptr ? headA : curB->next;
    }
    return curA;
}

int main() {
    ListNode* headA = new ListNode(4);
    ListNode* curA = headA;
    curA->next = new ListNode(1);
    curA = curA->next;
    curA->next = new ListNode(8);
    curA = curA->next;
    curA->next = new ListNode(4);
    curA = curA->next;
    curA->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    ListNode* curB = headB;
    curB->next = new ListNode(0);
    curB = curB->next;
    curB->next = new ListNode(1);
    curB = curB->next;
    curB->next = new ListNode(8);
    curB = curB->next;
    curB->next = new ListNode(4);
    curB = curB->next;
    curB->next = new ListNode(5);

    ListNode* res = getIntersectionNode(headA, headB);
    cout << res->val << endl;
    return 0;
}

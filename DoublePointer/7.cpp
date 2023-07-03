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
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lenA = 0, lenB = 0;
    while (curA != nullptr) {
        lenA++;
        curA = curA->next;
    }
    while (curB != nullptr) {
        lenB++;
        curB = curB->next;
    }
    curA = headA;
    curB = headB;
    if (lenB > lenA) {
        swap(lenA, lenB);
        swap(curA, curB);
    }
    int gap = lenA - lenB;
    while (gap--) {
        curA = curA->next;
    }
    while (curA != nullptr) {
        if (curA == curB) {
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return nullptr;
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
    curB->next = headA->next->next;

    ListNode* res = getIntersectionNode(headA, headB);
    cout << res->val << endl;
    return 0;
}

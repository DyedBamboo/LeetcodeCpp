/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 01:13:25
 * @LastEditTime: 2023-06-22 01:13:31
 * @Description: Leetcode 24 两两交换链表中的节点
 * @FilePath: \LeetcodeCpp\List\4.cpp
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

ListNode* swapPairs(ListNode* head) {
    ListNode* dumpyHead = new ListNode();
    dumpyHead->next = head;
    ListNode* last = dumpyHead;
    ListNode* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        ListNode* next = cur->next;
        cur->next = next->next;
        next->next = cur;
        last->next = next;
        last = cur;
        cur = cur->next;
    }
    return dumpyHead->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i <= 5; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    ListNode* res = swapPairs(head);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
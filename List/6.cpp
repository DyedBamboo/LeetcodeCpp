/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 01:47:21
 * @LastEditTime: 2023-06-22 01:47:21
 * @Description: Leetcode 19 删除链表的倒数第N个节点
 * @FilePath: \LeetcodeCpp\List\6.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* slow = dummyHead;
    ListNode* fast = dummyHead;
    while(n-- && fast != nullptr) {
        fast = fast->next;
    }
    fast = fast->next;
    while(fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummyHead->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i < 6; ++i) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    ListNode* res = removeNthFromEnd(head, 2);
    while (res != nullptr) {
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}
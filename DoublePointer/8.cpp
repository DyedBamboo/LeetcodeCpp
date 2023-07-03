/***
 * @Author: RanZhuJun
 * @Date: 2023-07-03 19:38:28
 * @LastEditTime: 2023-07-03 19:38:36
 * @Description: leetcode  142.环形链表II
 * @FilePath: \LeetcodeCpp\DoublePointer\8.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow) {
            ListNode* ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}

int main() {
    ListNode* head = new ListNode(3);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(0);
    cur = cur->next;
    cur->next = new ListNode(-4);
    cur = cur->next;
    cur->next = head->next;
    ListNode* res = detectCycle(head);
    int pos = 0;
    while (head != res) {
        head = head->next;
        pos++;
    }
    cout << pos << endl;
    return 0;
}
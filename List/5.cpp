/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 01:37:31
 * @LastEditTime: 2023-06-22 01:37:37
 * @Description: leetcode 19 删除链表的倒数第N个节点
 * @FilePath: \LeetcodeCpp\List\5.cpp
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dumpyHead = new ListNode();
    dumpyHead->next = head;
    ListNode* fast = dumpyHead;
    ListNode* slow = dumpyHead;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* del = slow->next;
    slow->next = del->next;
    delete del;
    return dumpyHead->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int i = 2; i <= 5; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    ListNode* res = removeNthFromEnd(head, 2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
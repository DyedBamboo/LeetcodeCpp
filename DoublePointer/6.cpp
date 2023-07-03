/***
 * @Author: RanZhuJun
 * @Date: 2023-07-03 18:55:22
 * @LastEditTime: 2023-07-03 18:55:28
 * @Description: leetcode 19.删除链表的倒数第N个节点
 * @FilePath: \LeetcodeCpp\DoublePointer\6.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>

using namespace std;

struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val), next(nullptr) {}
};

LinkedNode* removeNthFromEnd(LinkedNode* head, int n) {
    LinkedNode* dummyHead = new LinkedNode(0);
    dummyHead->next = head;
    LinkedNode* slow = dummyHead;
    LinkedNode* fast = dummyHead;
    while (n-- && fast != nullptr) {
        fast = fast->next;
    }
    fast = fast->next;
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    delete dummyHead;
    return head;
}

int main() {
    LinkedNode* head = new LinkedNode(1);
    LinkedNode* cur = head;
    for (int i = 2; i <= 5; ++i) {
        LinkedNode* newNode = new LinkedNode(i);
        cur->next = newNode;
        cur = cur->next;
    }
    LinkedNode* res = removeNthFromEnd(head, 2);
    while (res != nullptr) {
        cout << res->val;
        LinkedNode* temp = res;
        res = res->next;
        delete temp;
    }
    return 0;
}
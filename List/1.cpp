/***
 * @Author: RanZhuJun
 * @Date: 2023-06-21 21:12:08
 * @LastEditTime: 2023-06-21 21:12:12
 * @Description: leetcode 203 移除链表元素
 * @FilePath: \Cpp\List\1.cpp
 * @版权声明 RanZhuJun
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dumpyHead = new ListNode();
    dumpyHead->next = head;
    ListNode* last = dumpyHead;
    ListNode* cur = head;
    while (cur != nullptr) {
        if (cur->val == val) {
            last->next = cur->next;
            cur = cur->next;
        } else {
            last = cur;
            cur = cur->next;
        }
    }
    return head;
}

ListNode* InputList(void) {
    int n, val, k;
    ListNode* Head = new ListNode();
    ListNode* cur = Head;
    cout << "请输入链表的长度n和需要删除的节点位置k(空格隔开):" << endl;
    cin >> n >> k;
    cout << "请依次输入链表的" << n << "个节点值(空格隔开):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (i == 0) {
            cur->val = val;
            cur->next = nullptr;
        } else {
            ListNode* newNode = new ListNode();
            newNode->val = val;
            newNode->next = nullptr;
            cur->next = newNode;
            cur = newNode;
        }
    }

    Head = removeElements(Head, val);
    return Head;
}

void PrintList(ListNode* Head) {
    while (Head) {
        cout << Head->val;
        if (Head->next) {
            cout << " -> ";
        }
        Head = Head->next;
    }
    cout << endl;
}

int main() {
    ListNode* List = InputList();
    PrintList(List);
    return 0;
}

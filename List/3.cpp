/***
 * @Author: RanZhuJun
 * @Date: 2023-06-21 23:05:23
 * @LastEditTime: 2023-06-21 23:05:27
 * @Description: leetcode 206 翻转链表
 * @FilePath: \Cpp\List\3.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>

using namespace std;

struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val), next(nullptr) {}
};

LinkedNode* InputList() {
    int n;
    cout << "请输入链表大小：" << endl;
    cin >> n;
    int val;
    LinkedNode* dummyHead = new LinkedNode(0);
    LinkedNode* cur = dummyHead;

    cout << "请输入链表节点值(空格隔开):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        LinkedNode* newNode = new LinkedNode(val);
        cur->next = newNode;
        cur = cur->next;
    }
    LinkedNode* result = dummyHead->next;
    delete dummyHead;

    return result;
}

LinkedNode* reverseList(LinkedNode* head) {
    LinkedNode* temp;
    LinkedNode* cur = head;
    LinkedNode* pre = nullptr;
    while(cur) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

void printList(LinkedNode* head) {
    LinkedNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    LinkedNode* head =  InputList();
    printList(head);
    head = reverseList(head);
    printList(head);
}
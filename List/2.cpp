/***
 * @Author: RanZhuJun
 * @Date: 2023-06-21 22:10:54
 * @LastEditTime: 2023-06-21 22:10:58
 * @Description: leetcode 707 设计链表
 * @FilePath: \Cpp\List\2.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>

using namespace std;

class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index < 0 || index > _size - 1) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        if (index < 0)
            index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        ++_size;
    }

    void deleteAtIndex(int index) {
        if (index > _size)
            return;
        if (index < 0)
            index = 0;
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }

    void printList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};

int main() {
    MyLinkedList list;
    list.addAtHead(3);
    list.addAtTail(4);
    list.addAtTail(5);
    list.addAtTail(6);
    list.addAtTail(7);
    list.printList();
    list.addAtTail(2);
    list.printList();

    cout << list.get(3) << endl;
    list.addAtIndex(3, 1);
    list.printList();
    list.deleteAtIndex(3);
    list.printList();
    return 0;
}
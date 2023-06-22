/***
 * @Author: RanZhuJun
 * @Date: 2023-06-22 12:21:30
 * @LastEditTime: 2023-06-22 12:21:41
 * @Description: leetcode 142 环形链表 II
 * @FilePath: \LeetcodeCpp\List\8.cpp
 * @版权声明 RanZhuJun
 */
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 快慢指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            if (fast == slow)
            {
                ListNode *ptr = head;
                while (ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

int main()
{
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    Solution solution;
    ListNode *res = solution.detectCycle(head);
    cout << res->val << endl;
    return 0;
}

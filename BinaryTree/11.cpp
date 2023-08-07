/**
 * @file 11.cpp
 * @author RanZhuJun
 * @date 2023-08-07
 * @brief leetcode 117 填充每个节点的下一个右侧节点指针 II
 *
 * @copyright RanZhuJun 2023
 *
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node* connect(Node* root) {
    queue<Node*> que;
    if (root != nullptr) {
        que.push(root);
    }
    while (!que.empty()) {
        int size = que.size();
        Node* pre = nullptr;
        for (int i = 0; i < size; i++) {
            Node* cur = que.front();
            que.pop();
            if (pre != nullptr) {
                pre->next = cur;
            }
            pre = cur;
            if (cur->left != nullptr) {
                que.push(cur->left);
            }
            if (cur->right != nullptr) {
                que.push(cur->right);
            }
        }
    }
    return root;
}

void releaseMemory(Node* root) {
    if (root == nullptr) {
        return;
    }
    releaseMemory(root->left);
    releaseMemory(root->right);
    delete root;
    root = nullptr;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    Node* root = new Node(vec[0]);
    root->left = new Node(vec[1]);
    root->right = new Node(vec[2]);
    root->left->left = new Node(vec[3]);
    root->left->right = new Node(vec[4]);
    root->right->left = new Node(vec[5]);
    root->right->right = new Node(vec[6]);

    root = connect(root);
    Node* cur = root;
    while (cur != nullptr) {
        Node* tmp = cur;
        while (tmp != nullptr) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
        cur = cur->left;
    }
    releaseMemory(root);
    return 0;
}
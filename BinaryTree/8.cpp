/**
 * @file 8.cpp
 * @author RanZhuJun
 * @date 2023-08-07
 * @brief N叉树的层序遍历
 *
 * @copyright RanZhuJun 2023
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node(){};
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    queue<Node*> que;
    if (root != nullptr)
        que.push(root);
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            Node* node = que.front();
            que.pop();
            vec.push_back(node->val);
            for (auto child : node->children) {
                que.push(child);
            }
        }
        res.push_back(vec);
    }

    return res;
}

void releaseMemory(Node* root) {
    if (root == nullptr)
        return;
    for (auto child : root->children) {
        releaseMemory(child);
    }
    delete root;
}

int main() {
    Node* root = new Node(1);
    Node* node1 = new Node(3);
    Node* node2 = new Node(2);
    Node* node3 = new Node(4);
    Node* node4 = new Node(5);
    Node* node5 = new Node(6);
    vector<Node*> children1;
    children1.push_back(node1);
    children1.push_back(node2);
    children1.push_back(node3);
    root->children = children1;
    vector<Node*> children2;
    children2.push_back(node4);
    children2.push_back(node5);
    node1->children = children2;
    vector<vector<int>> res = levelOrder(root);

    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    releaseMemory(root);
    return 0;
}
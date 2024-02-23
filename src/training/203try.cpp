#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode* next):val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElement(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};

int main() {
    // 创建链表：1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, 
                        new ListNode(3, new ListNode(4, new ListNode(5, 
                        new ListNode(6)))))));

    Solution solution;
    head = solution.removeElement(head, 6); // 移除所有值为 6 的节点

    // 打印更新后的链表
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 释放链表占用的内存
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
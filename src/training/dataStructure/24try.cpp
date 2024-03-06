#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode* next):val(x), next(next) {}

};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;
            
            cur->next = cur->next->next;
            cur->next->next = tmp;
            tmp->next = tmp1;
            //更新cur
            cur = cur->next->next;

        }
        return dummyHead->next;
    }

    // 辅助函数，用于创建一个链表
    ListNode* createList(const std::vector<int>& values) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        for (int value : values) {
            cur->next = new ListNode(value);
            cur = cur->next;
        }
        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }

    // 辅助函数，用于打印链表
    void printList(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

};

int main() {
    Solution sol;
    // 创建链表
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = sol.createList(values);

    // 打印原始链表
    std::cout << "Original List: ";
    sol.printList(head);

    // 反转链表
   
    ListNode* swapNode = sol.swapPairs(head);

    // 打印反转后的链表
    std::cout << "swap List: ";
    sol.printList(swapNode);
    
    return 0;
}
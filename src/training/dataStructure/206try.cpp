#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp;
        // ListNode* dummyHead = new ListNode(0);
        // dummyHead->next = head;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre; //翻转操作
            //更新pre和cur指针
            pre = cur;
            cur = tmp;
        }
        return pre;

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
   
    ListNode* reversedHead = sol.reverseList(head);

    // 打印反转后的链表
    std::cout << "Reversed List: ";
    sol.printList(reversedHead);

    return 0;
}

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode* next):val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        // n++;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        //删除节点
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

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
   
    ListNode* swapNode = sol.removeNthFromEnd(head, 3);

    // 打印反转后的链表
    std::cout << "swap List: ";
    sol.printList(swapNode);
    
    return 0;
}


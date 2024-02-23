# include <iostream>

struct ListNode {
    int val;
    ListNode *next = nullptr;
    ListNode(int x):val(x),next(nullptr) {};
};


int main () {
    int n, val;
    ListNode* headNode = new ListNode(0);
    while (std::cin >> n) {
        ListNode *cur = headNode; //定义一个临时变量来构建链表
        for (int i = 0; i < n; i++) {
            std::cin >> val;
            ListNode* newNode = new ListNode(val);
            cur->next = newNode;
            cur = cur->next;
        }
        cur = headNode;
        while (cur->next != nullptr) {
            std::cout << cur->next->val << " " ;
            cur = cur->next;
        }
        std::cout << std::endl;
    }
    return 0;
}
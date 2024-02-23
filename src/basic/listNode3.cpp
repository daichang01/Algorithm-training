#include <iostream>

struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode(int x):val(x),next(nullptr){};
};

void printListNode(ListNode *headNode) {
    ListNode* cur = headNode;
    while (cur->next != nullptr) {
        std::cout << cur->next->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main() {
    int k;//构建链表的长度
    while (std::cin >> k) {
        int val;
        ListNode *headNode = new ListNode(0);
        ListNode *cur = headNode;  
        for (int i = 0; i < k; i++) {
            std::cin >> val;
            //*******
            ListNode *newNode = new ListNode(val);
            cur->next = newNode;
            cur = cur->next;
        }
        
        int s;//后续会有s行输入
        std::cin >> s;
        //*********
        int ListLen = k;
        while (s--) {
            int n,x;
            std::cin >> n >> x;
            if (n <= 0 || n > ListLen) {
                std::cout << "Insertion position is invalid." << std::endl;
                continue;
            }
            cur = headNode;
            //*******
            for (int i = 1; i < n; i++) {    
                cur = cur->next;
            }
            //插入节点
            ListNode* newListNode = new ListNode(x);
            ListNode* temp = cur->next;
            cur->next = newListNode;
            newListNode->next = temp;
            ListLen += 1;

            printListNode(headNode);
        }

        int l,m;
        std::cin >> l;
        while (l--) {
            std::cin >> m;
            if (m <= 0 || m > ListLen) {
                std::cout << "Deletion position is invalid." << std::endl;
                continue;
            }
            cur = headNode;
            for (int i = 1; i < m; i++) {
                cur = cur->next;
            }
            //删除节点
            cur->next = cur->next->next;
            ListLen -= 1;

            if (ListLen != 0) printListNode(headNode);
        }

    }
    return 0;
}
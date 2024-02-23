# include <iostream>

struct ListNode {
    int val;
    ListNode *next = nullptr;
    ListNode(int x) : val(x), next(nullptr) {};
};

int main () {
    int n, m;
    while (std::cin >> n >> m) {
        ListNode *headNode = new ListNode(0);
        ListNode *cur = headNode;
        int val;
        int index;
        for (int i = 0; i < n; i++) {
            std::cin >> val;
            ListNode* newNode = new ListNode(val);
            cur->next = newNode;
            cur = cur->next;
        }
        for (int i = 0; i < m; i++) {
            std::cin >> index;
            cur = headNode;
            
            while(index--) {
                if (cur != nullptr) {
                    cur = cur->next;
                }
                else {
                    break;
                }
            }
            if (cur == nullptr || cur == headNode) {
                std::cout << "Output position out of bounds." << std::endl;
            }
            else {
                std::cout << cur->val << std::endl;
            }

        }
    }


    return 0;
}
# include <iostream>

class MyLinkList {
public:
    //定义链表
    struct ListNode {
        int val;
        ListNode *next = nullptr;
        ListNode(int x):val(x), next(nullptr) {}
    };

    MyLinkList() {
        _dummyHead = new ListNode(0);
        _size = 0;
        
    }

    int get(int index) {
        ListNode* cur = _dummyHead->next;
        if (index < 0 || index > (_size - 1)) {
            return -1;
        }
       
        while (index--) {
            cur = cur->next;
        }
        return cur->val;

       
    }

    void addAtHead (int val) {
        // ListNode* cur = _dummyHead->next; 不需要cur指针
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size ++;
    }

    void addAtTail(int val) {
        ListNode* cur = _dummyHead;
        ListNode* newNode = new ListNode(val);
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size ++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size) {
            return;
        }
        else {
            ListNode* cur = _dummyHead;
            while (index--) {  
                cur = cur->next;
            }
            ListNode* newNode = new ListNode(val);
            newNode->next = cur->next;
            cur->next = newNode;
            _size ++;
            
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > (_size - 1)) {
            return;
        }
        else {
            ListNode* cur = _dummyHead;
            while (index --) {
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            
            delete tmp;
            tmp=nullptr;
            _size--;
        }
    }

    void printListNode() {
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            std::cout << cur->next->val << " ";
            cur  = cur->next;
        }
        std::cout << std::endl;
    }

private:
    int _size;
    ListNode* _dummyHead;

};


int main() {
    MyLinkList myList;

    // Add elements to the list
    myList.addAtHead(1);
    myList.addAtTail(2);
    myList.addAtTail(3);
    myList.addAtIndex(1, 4);  // Add 4 at index 1

    // Print the current list
    std::cout << "Current List: ";
    myList.printListNode();

    // Get and print an element
    std::cout << "Element at index 2: " << myList.get(2) << std::endl;

    // Delete an element
    myList.deleteAtIndex(1);

    // Print the list after deletion
    std::cout << "List after deletion: ";
    myList.printListNode();

    return 0;
}

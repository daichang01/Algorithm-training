#include <iostream>
#include <string>
#include <cctype> // 用于isdigit函数

class Node {
public:
    char data;
    Node* next;

    Node(char data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // 添加新字符到链表末尾
    void append(char data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 将链表内容转换为字符串，并将数字替换为"number"
    std::string convertToString() {
        std::string result;
        Node* current = head;
        while (current) {
            if (std::isdigit(current->data)) {
                result += "number";
            } else {
                result += current->data;
            }
            current = current->next;
        }
        return result;
    }

    // 析构函数，用于释放链表中的所有节点
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    std::string input = "a1b2c3";
    LinkedList list;

    // 将输入字符串的每个字符添加到链表中
    for (char c : input) {
        list.append(c);
    }

    std::string result = list.convertToString();
    std::cout << result << std::endl; // 输出: anumberbnumbercnumber

    return 0;
}

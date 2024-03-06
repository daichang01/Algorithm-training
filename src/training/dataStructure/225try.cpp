#include <iostream>
#include <queue>

class MyStack {
public:
    std::queue<int> qe;
    MyStack() {

    }
    
    void push(int x) {
        qe.push(x);
    }
    
    int pop() {
        int n = qe.size() - 1;
        while (n--) {
            qe.push(qe.front());
            qe.pop();
        }
        int res = qe.front();
        qe.pop();
        return res;
    }
    
    int top() {
        return qe.back();
    }
    
    bool empty() {
        return qe.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    std::cout << stack.pop() << std::endl;   // 输出 2
    std::cout << (stack.empty() ? "true" : "false") << std::endl; // 输出 false
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
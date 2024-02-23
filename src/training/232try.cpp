#include <iostream>
#include <queue>
#include <stack>

class MyQueue {
public:
    std::stack<int> stIn;
    std::stack<int> stOut;  
    MyQueue() {
        
    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop();
        stOut.push(res);
        return res;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    MyQueue* queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    std::cout << queue->peek() << std::endl;  // 输出 1
    std::cout << queue->pop() << std::endl;   // 输出 1
    std::cout << (queue->empty() ? "true" : "false") << std::endl; // 输出 false

    delete queue; // Don't forget to free the allocated memory

}
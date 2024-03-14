#include <iostream>
using namespace std;

class Interface {
public:
    virtual void operation() = 0;  // 纯虚函数
};

class Implement : public Interface {
public:
    void operation() override {
        cout << "Implemented operation" << endl;
    }
};

int main() {
    Implement imp;
    imp.operation();  // 调用实现的operation方法
    return 0;
}

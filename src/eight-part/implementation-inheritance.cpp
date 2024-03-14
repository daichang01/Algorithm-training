#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base show function" << endl;
    }
};

class Derived : public Base {
    // 继承Base的show方法
};

int main() {
    Derived d;
    d.show();  // 调用继承自Base类的show方法
    return 0;
}

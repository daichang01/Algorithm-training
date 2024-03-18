#include <iostream>

class MyClass {
public:
    mutable int cacheCount;
    int value;

    MyClass(int val): value(val), cacheCount(0) {}

    int getValue() const {
        cacheCount ++; //即使在const函数中也可以修改
        return value;
    }
};

int main() {
    const MyClass obj(42);
    std::cout << obj.getValue() << std::endl; //输出42
    std::cout << obj.cacheCount << std::endl; //输出1
    return 0;
}
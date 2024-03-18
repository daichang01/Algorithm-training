#include <iostream>
#include <memory> // 包含 unique_ptr

class Test {
public:
    Test() { std::cout << "Test Constructor\n"; }
    ~Test() { std::cout << "Test Destructor\n"; }
    void greet() { std::cout << "Hello, World!\n"; }
};

int main() {
    // 创建一个 unique_ptr 实例，管理一个 Test 对象
    std::unique_ptr<Test> ptr = std::make_unique<Test>();

    // 使用 -> 操作符访问 Test 实例的成员
    ptr->greet();

    // 不需要手动删除，当 ptr 离开作用域时，Test 对象会被自动销毁
}

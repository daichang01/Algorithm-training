#include <iostream>

class MyClass{
public:
    static int staticValue; //静态成员变量

    MyClass() {
        staticValue ++;
    }

    static void staticFunction() {
        std::cout << "Static value is" << staticValue << std::endl;
    }
};

int MyClass::staticValue = 0; //静态成员变量的定义和初始化

int main() {
    MyClass obj1, obj2, obj3;
    MyClass::staticFunction(); //调用静态成员函数
    return 0;
}
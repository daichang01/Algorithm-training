#include <iostream>

class Base{};
class Derived : public Base{};



int main() {
    double pi = 3.14159;
    int integerPi = static_cast<int>(pi); //基本数据类型转换
    std::cout << integerPi << std::endl;
    Base *b = new Derived();
    Derived* b = static_cast<Derived*>(b); //下行转换，不安全
    return 0;
}



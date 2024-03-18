#include <iostream>

class Myclass {
public:
    explicit Myclass(int x) {
        std::cout << "MyClass constrcted with value" << x << std::endl;
    }
};

void function(Myclass obj) {
    //do sometion with obj
}

int main() {
    Myclass obj1(10);
    //function(20)  //错误，这会尝试隐式转换int到Myclass， 但构造函数是explicit
    function(Myclass(20)); // 正确，显式转换
    return 0;
}
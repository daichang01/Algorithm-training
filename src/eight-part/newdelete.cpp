#include <iostream>

class Myclass{
public:
    Myclass() {
        std::cout << "constructor called" << std::endl;
    }
    ~Myclass() {
        std::cout << "destructor called" << std::endl;
    }
};

int main() {
    Myclass* obj = new Myclass(); //分配内存并构造函数
    delete obj;
}
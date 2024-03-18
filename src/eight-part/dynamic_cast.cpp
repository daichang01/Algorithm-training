#include <iostream>

class Base {
public:
    virtual void print() { std::cout << "Base" << std::endl; }
};

class Derived : public Base {
public:
    void print() override { std::cout << "Derived" << std::endl; }
};

int main() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b); //安全的下行转换
    if(d) d->print(); //如果转换成功，则不为nullptr

}
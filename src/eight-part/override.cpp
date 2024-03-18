#include <iostream>

class Base {
public:
    virtual void show() const {
        std::cout << "Base show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() const override {
        std::cout << "Derived show" << std::endl;
    }
};
// 解释const的作用
// 当show方法被声明为const时，它告诉编译器和程序员这个方法不会修改对象的任何成员变量。
// 这允许show方法在const对象或const对象引用/指针上被调用。
// 在继承关系中，当父类中的方法被声明为const时，子类重写该方法也必须保持相同的const性质，以保证多态行为的一致性。
int main() {
    Base* basePtr = new Base();
    Base* derivedPtr = new Derived();

    basePtr->show(); //调用Base类的show方法
    derivedPtr->show(); //虽然是Base类的指针，但因为指向Derived对象，所以调用Derived类的show方法;

    delete basePtr;
    delete derivedPtr;
    return 0;


}
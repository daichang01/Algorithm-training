class MyClass {
public:
    int publicVar;    // 可以被任何人访问
    void publicFunc() {}  // 同上

protected:
    int protectedVar;  // 可以被派生类访问
    void protectedFunc() {}  // 同上

private:
    int privateVar;    // 只能被MyClass访问
    void privateFunc() {}  // 同上
};

class DerivedClass : public MyClass {
    void exampleFunc() {
        publicVar = 1;       // OK: 访问公有成员
        protectedVar = 2;    // OK: 访问受保护成员
        // privateVar = 3;   // 错误: 不能访问私有成员
    }
};

int main() {
    MyClass obj;
    obj.publicVar = 1;    // OK: 访问公有成员
    // obj.protectedVar = 2; // 错误: 不能访问受保护成员
    // obj.privateVar = 3;  // 错误: 不能访问私有成员
}
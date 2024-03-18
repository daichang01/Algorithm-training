#include <iostream>

typedef int Integer;
typedef int* IntPtr;
typedef int arr10[10]; // 定义一个包含10个整数的数组类型

int main() {
    Integer a = 5;
    IntPtr ptr = &a;
    arr10 myArray; // 使用 typedef 定义的数组类型创建数组

    std::cout << "a: " << a << std::endl;
    std::cout << "Value pointed by ptr: " << *ptr << std::endl;
}

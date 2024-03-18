#include <iostream>

int main() {
    int x = 10; // 普通变量
    int* ptr = &x; // 指针，存放x的地址
    int** ptr_to_ptr = &ptr; // 指向指针的指针，存放ptr的地址
    
    // 修改通过指针指向的变量的值
    *ptr = 20;
    
    // 打印x的值来验证改变
    std::cout << "x: " << x << std::endl;
    
    // 使用指向指针的指针来改变x的值
    **ptr_to_ptr = 30;
    
    // 再次打印x的值来验证改变
    std::cout << "x after change through ptr_to_ptr: " << x << std::endl;
    
    int* ptr_to_null = nullptr; // 指向空值的指针
    std::cout << "Pointer to null: " << ptr_to_null << std::endl;

    return 0;
}

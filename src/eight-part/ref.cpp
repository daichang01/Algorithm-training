#include <iostream>

int main() {
    int y = 50;
    int& ref_to_y = y; // y的引用
    
    // 通过引用改变y的值
    ref_to_y = 60;
    
    // 打印y的值来验证改变
    std::cout << "y after change through ref_to_y: " << y << std::endl;

    // 引用一旦被初始化为某个变量的别名后，就不能再改变为别的变量的别名
    // 下面的代码是错误的，会导致编译错误
    // int z = 70;
    // ref_to_y = &z; // 错误：引用不可以重新赋值为另一个变量的地址

    return 0;
}

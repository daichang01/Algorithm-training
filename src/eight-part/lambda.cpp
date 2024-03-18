#include <iostream>

int main()
{
    auto lam = []
    { std::cout << "Hello, World!"; return 88; };
    auto ret = lam();              // 调用Lambda表达式
    std::cout << ret << std::endl; // 输出88
}

int a = 1, b = 2, c = 3;

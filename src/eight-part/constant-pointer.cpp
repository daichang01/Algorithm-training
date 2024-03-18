#include <iostream>

int main() {
    int value = 10;
    const int* ptr = &value; // 或 int const *ptr = &value;
    //*ptr = 20; // 错误，不能通过常量指针修改其指向的值
    value = 20; // 正确，value不是const，可以直接修改

    int value2 = 30;
    ptr = &value2; // 正确，可以改变ptr指向的地址
}

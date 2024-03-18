#include <cstdlib> //对于malloc 和free
#include <iostream>

struct  Myclass {
    Myclass() {
        std::cout << "construct cannot be called explicitly" << std::endl;
    }
};

int main() {
    Myclass* obj = (Myclass*)malloc(sizeof(Myclass)); //仅分配内存
    //由于malloc不调用构造函数，上面的输出不会执行
    free(obj); //释放内存
}
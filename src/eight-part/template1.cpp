#include <iostream>
using namespace std;

// 主模板
template<typename T1, typename T2>
void fun(T1 a, T2 b) {
    cout << "模板函数" << endl;
}

// 全特化版本
template<>
void fun<int, char>(int a, char b) {
    cout << "全特化" << endl;
}

int main() {
    fun(10, 'a');  // 调用全特化版本
    fun(10, 3.14);  // 调用主模板
    return 0;
}

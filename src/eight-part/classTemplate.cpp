#include <iostream>
using namespace std;

// 主模板
template<typename T1, typename T2>
class Test {
public:
    Test(T1 i, T2 j) : a(i), b(j) { cout << "模板类" << endl; }
private:
    T1 a;
    T2 b;
};

// 全特化
template<>
class Test<int, char> {
public:
    Test(int i, char j) : a(i), b(j) { cout << "全特化" << endl; }
private:
    int a;
    char b;
};

// 偏特化
template <typename T2>
class Test<char, T2> {
public:
    Test(char i, T2 j) : a(i), b(j) { cout << "偏特化" << endl; }
private:
    char a;
    T2 b;
};

int main() {
    Test<double, double> t1(1.1, 2.2);  // 调用主模板
    Test<int, char> t2(10, 'a');  // 调用全特化
    Test<char, int> t3('a', 10);  // 调用偏特化
    return 0;
}

#include <iostream>

class Vector2D {
public:
    float x, y;
    Vector2D(float x, float y): x(x), y(y) {}

    // 重载方式：在这个类中，+运算符是通过成员函数来重载的。这意味着这个操作符的左操作数必须是Vector2D的一个实例。
    //通过成员函数重载‘+’运算符
    Vector2D operator+(const Vector2D& rhs) const {
        return Vector2D(x + rhs.x, y+rhs.y);
    }

};

int main() {
    Vector2D v1(1.0, 2.0), v2(3.0, 4.0);
    Vector2D v3 = v1 + v2; //使用重载的‘+’运算符
    std::cout << "v3:(" << v3.x << "," << v3.y << ")" << std::endl;
    return 0;
}
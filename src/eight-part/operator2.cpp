#include <iostream>

class Point{
public:
    int x, y;
    Point(int x, int y):x(x), y(y) {}
    
    //重载 ‘<<'为友元函数，允许访问私有成员
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

int main() {
    Point p(5, 10);
    std::cout << p <<std::endl;
    return 0;
}
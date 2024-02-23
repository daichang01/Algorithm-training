#include <iostream>
#include <string>
#include <vector>
// 引入iomanip库文件，用于控制输出格式
#include <iomanip>

class Shape {
public:
    virtual double CalculateArea() const = 0;
    virtual std::string GetType() const = 0;
};

class Rectangle: public Shape {
public:
    Rectangle(int width, int height):width(width), height(height) {}

    std::string GetType() const override {
        return "Rectangle";
    }
    double CalculateArea() const override{
        return height * width;
    }
private:
    double height;
    double width;
};

class Circle : public Shape {
public:
    Circle(double radiuspara):radius(radiuspara) {}
    std::string GetType() const override {
        return "Circle";
    }
    double CalculateArea() const override{
        return radius * radius * 3.14;
    }
private:
    double radius;
    std::string type;
};

int main() {
    // 定义一个容器，容纳 shape对象
    std::vector<Shape*> shapes;

    while (true) {
        std::string type;
        // 获取输入的 type类型
        std::cin >> type;

        if (type == "end") {
            break;
        }

        if (type == "rectangle") {
            // 获取输入的宽度和高度
            int width, height;
            std::cin >> width >> height;
            // 新建Rectangle对象
            shapes.push_back(new Rectangle(width, height));
        } else if (type == "circle") {
            int radius;
            // 获取输入的半径
            std::cin >> radius;
            // 新建 Radius 对象
            shapes.push_back(new Circle(radius));
        }
    }

    // 输出结果，控制小数位数为两位
    for (const Shape* shape : shapes) {
        // shape对象调用同一个方法，有不同的处理逻辑
        std::cout << shape->GetType() << " area: " << std::fixed << std::setprecision(2) << shape->CalculateArea() << std::endl;
    }
    return 0;
}
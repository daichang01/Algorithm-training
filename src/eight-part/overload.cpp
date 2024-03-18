#include <iostream>

class Myclass {
public:
    void display() const {
        std::cout << "display without parameter" << std::endl;
    }

    void display(int i) const {
        std::cout << "display with int: " << i << std::endl;
    }

    void display(double d) const {
        std::cout << "displat with double" << d << std::endl;
    }
};

int main() {
    Myclass obj;
    obj.display();
    obj.display(5);
    obj.display(3.14);
}
#include <iostream>
void function() {
    static int counter = 0; //静态局部变量
    std::cout << "function is called " << ++counter << "times" << std::endl;

}

int main() {
    for (int i = 0; i < 5; i++) {
        function();
    }
    return 0;
}
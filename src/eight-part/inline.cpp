#include <iostream>

inline int square(int x ) {
    return x* x;
}

int main() {
    int result = square(5);
    std::cout << "square of 5 is" << result << std::endl;
    return 0;
}
#include <iostream>
#include <climits> // 用于访问INT_MAX等

int main() {
    std::cout << "Size of data types on this system:\n";
    std::cout << "int is " << sizeof(int) << " bytes.\n";
    std::cout << "short is " << sizeof(short) << " bytes.\n";
    std::cout << "long is " << sizeof(long) << " bytes.\n";
    std::cout << "long long is " << sizeof(long long) << " bytes.\n";

    std::cout << "\nRange of data types on this system:\n";
    std::cout << "The maximum value of int = " << INT_MAX << ".\n";
    std::cout << "The minimum value of int = " << INT_MIN << ".\n";
    std::cout << "The maximum value of short = " << SHRT_MAX << ".\n";
    std::cout << "The minimum value of short = " << SHRT_MIN << ".\n";
    std::cout << "The maximum value of long = " << LONG_MAX << ".\n";
    std::cout << "The minimum value of long = " << LONG_MIN << ".\n";
    std::cout << "The maximum value of long long = " << LLONG_MAX << ".\n";
    std::cout << "The minimum value of long long = " << LLONG_MIN << ".\n";

    return 0;
}

#include <iostream>

int main () {
    int n;
    while(std::cin >> n) {
        int result = 0;
        while (n != 0) {
            int a = n % 10;
            n = n / 10;
            if (a % 2 == 0) {
                result += a;
            }
        }
        std::cout << result << std::endl;
        std::cout << std::endl;
    }
}


#include <iostream>

int main () {
    int n, a, b;
    while (std::cin >> n) {
        while (n --) {
            std::cin >> a;
            int sum = 0;
            while (a--) {
                std::cin >> b;
                sum += b;
            }
            std::cout << sum << std::endl;
            if (n != 0) std::cout << std::endl;
        }
    }
}
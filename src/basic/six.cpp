#include <iostream>
int main () {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = n; i > 0; i--) {
        std::cout << a[i - 1] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i += 2) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    for ( int i = 0; i < n; i++) {
        if (i == 0 || i == (n - 1)) {
            for (int j = 0; j < n; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        else {
            for (int j = 0; j < n; j++) {
                if(j == 0 || j == n - 1) {
                    std::cout << "*" ;
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        
    }
}


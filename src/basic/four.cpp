#include <iostream>

int main () {
    int n, sum = 0;
    int num[100];
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        else if(n > 0) {
            for(int i = 0; i < n; i++) {
                std::cin >> num[i];
                sum += num[i];
            }    
        }
        std::cout << sum << std::endl;
        sum = 0;
        
    }
    return 0;
}
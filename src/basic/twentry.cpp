#include <iostream>
#include <queue>
#include <string>

int main () {
    int n;
    std::cin >> n;
    std::queue<std::string> qs;
    std::string name;
    while (n--) {
        std::cin >> name;
        qs.push(name);
    }
    int m, k;
    std::cin >> m;
    while (m --) {
        std::cin >> k;
        if (k == 1 && !qs.empty()) {
            qs.pop();
        }
        else if (k == 2) {
            std::cin >> name;
            qs.push(name);
        }
    }
    if (!qs.empty()) {
        std::cout << qs.front() << std::endl;
    }
    else {
        std::cout << "There are no more people in the queue." << std::endl;
    }
    
}
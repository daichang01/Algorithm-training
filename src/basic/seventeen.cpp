#include <iostream>
#include <unordered_set>

int main () {
    int k;
    std::cin >> k;
    while (k--) {
        int m;
        std::cin >> m;
        std::unordered_set<int> unset;
        int val;
        while (m--) {
            std::cin >> val;
            unset.insert(val);
        }
        int n;
        std::cin >> n;
        if(unset.find(n) != unset.end()) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
}
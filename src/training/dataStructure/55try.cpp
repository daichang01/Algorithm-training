# include<iostream>
# include <string>
# include <algorithm>

int main() {
    int k;
    std::cin >> k;
    std::string s;
    std::cin >> s;
    if (k > s.size()) {
        std::cout << "out of range" << std::endl;
        return 0;
    }
    int len = s.size();
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + k);
    std::reverse(s.begin() + k, s.end());
    std::cout << s  << std::endl;

}
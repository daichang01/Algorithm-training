#include <iostream>
# include <string>

int main() {
    int n;
    std::cin >> n;
    std::getchar();
    while (n--) {
        std::string s;
        std::getline (std::cin, s);
        for (int i = 0; i < s.size(); i+= 2 ) {
            int temp = s[i];
            s[i] = s[i + 1];
            s[i + 1] = temp;
        }
        std::cout << s << std::endl;
    }
    return 0;
}
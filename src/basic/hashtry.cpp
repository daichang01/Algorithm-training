#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n;
    while (n--) {
        std::cin >> s;
        int count[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a'] += 1;
        }
        char result ;
        int times = 0;
        int index = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > times) {
                times = count[i];
                index = i;
            }
        }
        result = 'a' + index;
        std::cout << result << std::endl;
        
    }
    return 0;
}
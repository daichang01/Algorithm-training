#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            std::swap(s[i],s[j]);
        }
        
    }
};

int main() {
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);
    for (char c:s) {
            std::cout << c << " " ;
        }
    std::cout << std::endl;
}
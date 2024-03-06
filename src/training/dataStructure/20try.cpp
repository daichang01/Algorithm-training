#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        if (s.size() % 2 != 0) return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(')');
            }
            else if(s[i] == '[') {
                st.push(']');
            }
            else if(s[i] == '{') {
                st.push('}');
            }
            else if(st.empty() || st.top() != s[i]) {
                return false;
            }
            else {
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    std::string s = "(())[]{}";
    Solution sol;
    if(sol.isValid(s)) {
        std::cout << "valid string" <<std::endl;
    }
    else {
        std::cout << "unvalid string" << std::endl;
    }
}
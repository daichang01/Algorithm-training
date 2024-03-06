#include <iostream>
#include <stack>

class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }
        std::string res;
        res.resize(st.size());
        int n = st.size();
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

int main() {
    std::string s = "abbaca";
    Solution sol;
    std::string res = sol.removeDuplicates(s);
    std::cout << res <<std::endl;
}
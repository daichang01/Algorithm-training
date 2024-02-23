#include <iostream>
#include <vector>
#include <stack>
#include <string>
class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        int a,res;
        if (tokens.size() == 1) {
            res = std::stoi(tokens[0]);
            return res;
        }
        std::stack<std::string> st;
        for (std::string s:tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                st.push(s);
            }
            else {
                res = std::stoi(st.top());
                st.pop();
                a = std::stoi(st.top());
                st.pop();
                if (s == "+") {
                    res = a + res;
                }
                else if (s == "-") {
                    res = a - res;
                }
                else if (s == "*") {
                    res = a * res;
                }
                else if (s == "/") {
                    res = a / res;
                }
                st.push(std::to_string(res));
            }
        }
        return res;
    }
};

int main () {
    // std::vector<std::string> tokens = {"2","1","+","3","*"};
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution sol;
    int res = sol.evalRPN(tokens);
    std::cout << res << std::endl;
}
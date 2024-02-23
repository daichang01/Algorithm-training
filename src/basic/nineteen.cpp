#include <iostream>
#include <stack>

int main() {
    int n, m, opt, val, num;
    std::cin >> n;
    std::stack<int> st;
    while (n--) {
        std::cin >> val;
        st.push(val);
    }
    std::cin >> m;
    while (m--) {
        std::cin >> opt;
        if (opt == 1 && !st.empty()) st.pop();
        else {
            std::cin >> num;
            st.push(num);
        }
    }
    if (st.empty()) {
        std::cout << "all the dishes have been washed" << std::endl;
    }
    else {
        std::cout << st.top() << std::endl;
    }
}
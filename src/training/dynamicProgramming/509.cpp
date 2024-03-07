#include <iostream>
#include <vector>

class Solution {
public:
    int fib(int n) {
        std::vector<int> dp(n + 1);
        if (n <= 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2 ; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 5;
    int sum = sol.fib(n);
    std::cout << n << "sum:" << sum << std::endl;
    return 0;
}
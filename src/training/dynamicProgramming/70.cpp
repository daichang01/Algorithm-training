#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        std::vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 5;
    int sum = sol.climbStairs(n);
    std::cout << n << "sum:" << sum << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                //ditui
                dp[i] += dp[j - 1]* dp[i - j];
            }
        }
        // 打印dp
        // for (int i: dp) {
        //     std::cout << i << " ";
        // }
        return dp[n];
    }
};

int main() {
    int n = 3;
    Solution sol;
    int sum = sol.numTrees(n);
    std::cout << "sum: " << sum << std::endl;
    return 0;
}
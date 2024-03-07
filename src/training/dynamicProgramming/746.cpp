#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> dp(cost.size() + 1);
        // dp[i]的定义：到达第i台阶所花费的最少体力为dp[i]。
        dp[0] = 0;
        dp[1] = 0;
        int sum = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        // for (int i : dp) {
        //     std::cout << i <<  " ";
        // }
        // std::cout << std::endl;
        // return dp.back();
        return dp[cost.size()];
    }
};

int main() {
    std::vector<int> count = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution sol;
    int min =  sol.minCostClimbingStairs(count);
    std::cout << "sum: " << min << std::endl;
}
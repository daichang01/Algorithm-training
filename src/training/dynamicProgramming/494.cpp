#include <iostream>
#include <vector>
#include <cmath> // For std::abs

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        // 计算数组的总和
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        // 如果目标绝对值大于总和，或者 (target + sum) 为奇数，没有解
        if (abs(target) > sum || (target + sum) % 2 == 1) return 0;
        // 计算背包大小
        int bagSize = (target + sum) / 2;
        // 动态规划数组初始化
        std::vector<int> dp(bagSize + 1, 0);
        dp[0] = 1; // 总和为0的方法数为1
        // 动态规划解决背包问题
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int result = solution.findTargetSumWays(nums, target);
    std::cout << "Number of ways to reach target sum: " << result << std::endl;
    return 0;
}

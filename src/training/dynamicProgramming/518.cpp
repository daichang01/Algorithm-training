#include <iostream>
#include <vector>

class Solution
{
public:
    int change(int amount, std::vector<int> &coins)
    {
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        // 求得是排列数
        // for (int j = 0; j <= amount; j++)
        // { // 遍历背包容量
        //     for (int i = 0; i < coins.size(); i++)
        //     { // 遍历物品
        //         if (j - coins[i] >= 0)
        //             dp[j] += dp[j - coins[i]];
        //     }
        // }
        for (int i : dp)
        {
            std::cout << i << " ";
        }
        return dp[amount];
    }
};

int main()
{
    Solution sol;
    std::vector<int> coins = {1, 2, 5};
    int result = sol.change(5, coins);
    return 0;
}
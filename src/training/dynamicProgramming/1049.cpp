#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        std::vector<int> dp(1501, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) { //遍历物品
            for (int j = target; j >= stones[i]; j--) { //遍历背包
                dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        int last = sum - dp[target] - dp[target];
        //打印dp
        // for (int i = 0; i < sum; i ++) {
        //     std::cout << dp[i] << " " ;
        // }
        // std::cout << std::endl;
        return last;
    }
};

int main() {
    Solution sol;
    std::vector<int> stones = {2,7,4,1,8,1};
    int last = sol.lastStoneWeightII(stones);
    std::cout << "last:" << last << std::endl;
    return 0;
}
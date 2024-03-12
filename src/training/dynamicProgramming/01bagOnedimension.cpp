#include <iostream>
#include <vector>

void test_1_wei_bag_problem() {
    std::vector<int> weight = {1,3,4};
    std::vector<int> value = {15, 20 ,30};
    int bagweight = 4;

    //初始化
    std::vector<int> dp(bagweight + 1, 0);
    for (int i = 0; i < weight.size(); i++) {
        for (int j = bagweight;j >= weight[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);

        }
    }
    std::cout << dp[bagweight] << std::endl;
}

int main() {
    test_1_wei_bag_problem();
}
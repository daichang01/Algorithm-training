#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int integerBreak(int n) {
        //定义dp数组
        std::vector<int> dp(n+1, 0);
        //确定初始值
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                //递推公式
                dp[i] = std::max((j*(i-j)), std::max(j * dp[i - j],dp[i]));
            }
        }
            //打印dp数组
        // for (int i:dp) {
        //     std::cout << i << " " ;
        // }
        return dp[n];
    }

};

int main() {
    Solution sol;
    int n = 10;
    int max = sol.integerBreak(n);
    std::cout << "max:" << max << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        // 初始化动态规划数组
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        // 遍历字符串数组
        for (std::string str: strs) {
            int oneNum = 0, zeroNum = 0;
            // 计算当前字符串中0和1的数量
            for (char c: str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            // 更新动态规划数组
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = std::max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        // 返回最终结果
        return dp[m][n];
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    int maxForm = solution.findMaxForm(strs, m, n);
    std::cout << "Maximum number of strings that can be formed: " << maxForm << std::endl;
    return 0;
}

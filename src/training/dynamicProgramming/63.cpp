#include <iostream>
#include <vector>


class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //确定dp数组含义
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        //初始化dp数组
        for (int i = 0; i < m && (obstacleGrid[i][0] == 0); i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n && (obstacleGrid[0][i] == 0); i++) {
            dp[0][i] = 1;
        }
        //递推
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        //打印dp数组
        for (auto i:dp) {
            for (int j:i) {
                std::cout << j << " " ;
            }
            std::cout << std::endl;
        }
        return dp[m - 1][n - 1];
    }
};

int main () {
    std::vector<std::vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution sol;
    int sum = sol.uniquePathsWithObstacles(obstacleGrid);
    std::cout << "sum:" << sum << std::endl;
    return 0;
}


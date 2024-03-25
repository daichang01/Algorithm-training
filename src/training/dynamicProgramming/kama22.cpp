#include <iostream>
#include <vector> 

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(i - j >= 0) dp[i] += dp[i -j];   
        }
    }
    
    for (int i : dp) std::cout << i << " ";
    return 0;
}
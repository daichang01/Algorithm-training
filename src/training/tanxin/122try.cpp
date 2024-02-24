#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        std::vector<int> pricevary;
        for (int i = 1; i < prices.size(); i++) {
            int vary = prices[i] - prices[i - 1];
            pricevary.push_back(vary);
        }
        int result = 0;
        for (int i:pricevary) {
            if (i > 0) {
                result += i;
            }
        }
        return result;
    }

};

int main() {
    Solution sol;
    std::vector<int> prices = {7,1,5,3,6,4};
    int result = sol.maxProfit(prices);
    std::cout << "result:" << result << std::endl;
    return 0;
}

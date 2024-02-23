# include <iostream>
# include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int sum = 0;
        int result = INT32_MAX;
        int subL = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= target) {
                    subL = j - i + 1;
                    result=  result < subL ? result : subL;
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0:result;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution sol;
    int result = sol.minSubArrayLen(7, nums);
    std::cout << result <<std::endl;
}
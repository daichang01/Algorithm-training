#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        //滑动窗口法，双指针
        //首先移动右区间指针
        int i = 0;
        int result = INT32_MAX;
        int sublenth = 0;
        int sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                sublenth = j - i + 1;
                // result = result < sublenth ? result:sublenth;
                sum -= nums[i];
                i++;
                result = result < sublenth ? result:sublenth;
            }
        }
        return result == INT32_MAX ? 0:result;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution sol;
    int result = sol.minSubArrayLen(7,nums);
    std::cout << result << std::endl;
}
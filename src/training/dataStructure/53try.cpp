#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int count = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count < 0) {
                count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
            }

        }
        return result;
    }
};

int main () {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    int result = sol.maxSubArray(nums);
    std::cout << result << std::endl;
    return 0;
}
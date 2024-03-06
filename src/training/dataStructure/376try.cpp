#include <iostream>
#include <vector>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0;
        int preDiff = 0;
        int result = 1; //记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i+1] - nums[i];
            //出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result ++;
                preDiff = curDiff; //只在摆动变化的时候更新prediff
            }
        }
        return result;
    }
};

int main () {
    std::vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    Solution sol;
    int result = sol.wiggleMaxLength(nums);
    std::cout << result << std::endl;
    return 0;
}
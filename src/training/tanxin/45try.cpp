#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curdistance = 0; //当前覆盖的最远距离下标
        int ans = 0; //记录走的最大步数
        int nextdistance = 0; //下一步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i ++) {
            nextdistance = std::max(nums[i] + i,nextdistance);// 更新下一步覆盖
            if (i == curdistance) {
                ans ++;
                curdistance = nextdistance;
                if (nextdistance >= nums.size() - 1) break;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {2, 3, 1, 1, 4}; 
    int minJumps = solution.jump(nums);
    std::cout << "Minimum number of jumps required: " << minJumps << std::endl;
    return 0;
}

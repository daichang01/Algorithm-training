#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= cover; i++ ) {
            cover = std::max(cover, i + nums[i] );
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2,1,1,0,4};    
    bool result = sol.canJump(nums);
    if (result) {
        std::cout << "The array is jumpable." << std::endl;
    } else {
        std::cout << "The array is not jumpable." << std::endl;
    }
    return 0;
}
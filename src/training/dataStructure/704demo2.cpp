# include <iostream>
# include <vector>

//左闭右开
class Solution {
    public:
        int research (std::vector<int> nums, int target) {
            int left = 0;
            int right = nums.size();
            while (left < right) {
                int middle = (left + right) / 2;
                if (nums[middle] < target) {
                    left = middle + 1;
                }
                else if (nums[middle] > target) {
                    right = middle;
                }
                else {
                    return middle;
                }
            }
            return -1;
        }
};

int main () {
    std::vector<int> nums = {-1,2,3,4,6,7};
    int target = 5;
    Solution sol;
    int result = sol.research(nums, target);
    std::cout << result << std::endl;
    
}
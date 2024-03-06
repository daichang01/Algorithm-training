# include <iostream>
# include <vector>

class Solution {
    public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 0);
       int k = nums.size() - 1;
        for(int i = 0,j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                result[k--] = nums[i] * nums[i];
                // k--;
                i++;
            }
            else {
                result[k--] = nums[j] * nums[j];
                j--;
            }

        }
        return result;
    }

};

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    Solution sol;
    std::vector<int> result = sol.sortedSquares(nums);
    for (int i = 0; i < result.size(); i++) {
         std::cout << result[i] << " ";
    }
}
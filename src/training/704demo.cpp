# include <iostream>
# include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        // int middle = (left + right ) / 2;
        while (left <= right ) {
            int middle = (left + riight) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
                middle = (left + right) / 2;
            }
            else if (nums[middle] > target) {
                right = middle - 1;
                middle = (left + right) / 2;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> nums = {-1, 2, 4, 5, 6, 7};
    int target = 6;
    Solution sol;
    int result = sol.search(nums, target);
    std::cout << result << std::endl;

    return 0;
}
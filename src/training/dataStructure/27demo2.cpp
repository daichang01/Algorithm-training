#include <vector>
#include <iostream>

class Solution {
    public:
        //双指针
        int removeElement(std::vector<int> &nums, int target) {
            // int size = 0;
            int slow = 0;
            for (int fast = 0; fast < nums.size(); fast++) {
                if (nums[fast] != target) {
                    nums[slow] = nums[fast];
                    slow++;
                    // size++;
                }
            }
            return slow;
        }
};

int main() {
    int target = 5;
    std::vector<int> nums = {1, 4,5, 3, 6, 3, 3, 5};
    Solution sol;
    int size = sol.removeElement(nums, target);
    std::cout << size <<std::endl;
    for(int i = 0; i < nums.size(); i ++) {
        std::cout << nums[i] << " " ;
    }
}
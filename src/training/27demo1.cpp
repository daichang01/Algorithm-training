# include <iostream>
# include <vector>

class Solution {
    public:
        int removeElement(std::vector<int> &nums, int val) {
            //暴力解法
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                if (nums[i] == val) {
                    for (int j = i + 1; j < size; j++) {
                        nums[j-1] = nums[j];
                    }
                    i -- ;
                    size --;
                }
            }
         return size;
        }
};

int main() {
    int target = 5;
    std::vector<int> nums = {1,3,4,5,7,3,4,4,5};
    Solution sol;
    int size = sol.removeElement(nums,target);
    std::cout << size <<std::endl;
    for(int i = 0; i < nums.size(); i ++) {
        std::cout << nums[i] << " " ;
    }
}
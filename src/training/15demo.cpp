# include <iostream>
# include <vector>
# include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right --;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left ++;
                }
                else {
                    result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                    // 去重首先要确定一个三元数
                    while(right > left && nums[right] == nums[right - 1]) right --;
                    while(right > left && nums[left] == nums[left + 1]) left ++;
                    right --;
                    left ++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = solution.threeSum(nums);

    for (const auto& triplet : result) {
        std::cout << '[';
        for (const auto& num : triplet) {
            std::cout << num << ' ';
        }
        std::cout << "]\n";
    }

    return 0;
}
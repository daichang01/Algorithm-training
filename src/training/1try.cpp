#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            auto iter = map.find(tmp);
            if (iter == map.end()) {
                //  map.insert(nums[i], 0);
                map.insert(std::pair<int, int>(nums[i], i)); 
            }
            else {
                return {iter->second, i};
            }
        }
        return {};
    }
};

int main() {
    std::vector<int> nums = {2, 7, 11, 15}; // 示例数组
    int target = 9; // 目标值

    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No two sum solution found." << std::endl;
    }

    return 0;
}
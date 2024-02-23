#include <iostream>
#include <vector>


class Solution{
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int>& nums, int startIndex) {
        result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,2,3,4};
    std::vector<std::vector<int>> result = sol.subsets(nums);
    for(const auto& path: result) {
        std::cout << "[";
        for (const auto& num : path) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
}
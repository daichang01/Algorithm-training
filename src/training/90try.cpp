#include <iostream>
#include <vector>
#include <algorithm> //for std::sort


class Solution{
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int>& nums, int startIndex, std::vector<bool>& used) {
        result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            //used[i - 1] == true, 说明同一树枝candidates[i - 1]使用过
            //used[i -1] == false,说明同一树层candidates[i - 1]使用过
            //而我们要对同一树层使用过的元素进行跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i -1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); //sort the input vector
        std::vector<bool> used(nums.size(), false);
        result.clear();
        path.clear();
        backtracking(nums, 0, used);
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1,2,3,3};
    std::vector<std::vector<int>> result = sol.subsetsWithDup(nums);
    for(const auto& path: result) {
        std::cout << "[";
        for (const auto& num : path) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
}
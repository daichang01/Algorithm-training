#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(std::vector<int> & nums,  std::vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for ( int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i -1] == false) {
                continue;
            }
            if (used[i] == true) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;

        }
        return;
    }
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<bool> used(nums.size(), false);
        result.clear();
        path.clear();
        backtracking(nums, used);
        return result;
    }

};

int main() {
    Solution sol;
    std::vector<int> nums = {1,1,2,3};
    std::vector<std::vector<int>> result = sol.permuteUnique(nums);
    for (const auto &path:result) {
        for (const int num:path) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
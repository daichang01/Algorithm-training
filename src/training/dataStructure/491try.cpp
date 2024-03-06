#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(std::vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            result.push_back(path);
            //注意这里不要加return，因为要取树上的所有节点
        }
        //单层搜索
        std::unordered_set<int> uset; //使用set对本层元素进行去重
        for (int i = startIndex; i < nums.size(); i ++) {
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]); //记录这个元素在本层用过了，本层后面不能再用
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main() {
    std::vector<int> nums = {4,7,6,7};
    Solution sol;
    std::vector<std::vector<int>> result = sol.findSubsequences(nums);
    for (const auto& path: result) {
        for (int num:path) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(std::vector<int>& candidates, int target, int sum, int startIndex, std::vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
                        // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i -1] && used[i -1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0 ,0, used);
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    std::vector<std::vector<int>> result = sol.combinationSum2(candidates, target);

    std::cout << "所有组合的数字之和等于 " << target << " 的唯一组合为:\n";
    for (const auto& combination : result) {
        std::cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            std::cout << combination[i];
            if (i < combination.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    return 0;
}
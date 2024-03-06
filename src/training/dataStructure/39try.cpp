#include <iostream>
#include <vector>



class Solution{
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(std::vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // 不用i + 1，表示可以重复读取当前数字
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }

};


int main() {
    Solution sol;
    std::vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    std::vector<std::vector<int>> result = sol.combinationSum(candidates, target);

    std::cout << "Combinations summing to " << target << ":\n";
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
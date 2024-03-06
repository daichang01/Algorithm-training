#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static bool cmp(std::vector<int>& a, std::vector<int>& b) {
        return a[0] < b[0];
    }
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), cmp);
        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]){
                result.back()[1] = std::max(intervals[i][1], result.back()[1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> intervals ={{1,3},{2,6},{8,10},{15,18}};
    Solution sol;
    std::vector<std::vector<int>> result = sol.merge(intervals);
    for (auto i : result) {
        std::cout << "[";
        for (int j : i) {
            std::cout << j << " " ;
        }
        std::cout << "]";
    }
    return 0;
}
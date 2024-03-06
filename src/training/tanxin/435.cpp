#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static bool cmp (const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int count = 0;
        std::sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < intervals[i-1][1]) {
                count ++;
                intervals[i][1] = std::min(intervals[i-1][1], intervals[i][1]);
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> nums = {{1,2},{2,3},{3,4},{1,3}};
    int count = sol.eraseOverlapIntervals(nums);
    std::cout << "count:" << count << std::endl;
    return 0;
}
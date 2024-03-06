# include <iostream>
# include <vector>
# include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> result_set;
        std::unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return std::vector<int>(result_set.begin(), result_set.end());
    }
};

int main() {
    std::vector<int> nums1 = {1,2,2,5,1};
    std::vector<int> nums2 = {2,2,5,6};
    std::vector<int> result;
    Solution sol;
    result = sol.intersection(nums1, nums2);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}
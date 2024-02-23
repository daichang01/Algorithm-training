# include <iostream>
# include <unordered_map>
# include <vector>

class Solution {
public:
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
        std::unordered_map<int, int> umap;
        for (int a: nums1) {
            for (int b:nums2) {
                umap[a + b]++;
            }
        }
        int result = 0;
        for (int c: nums3) {
            for (int d: nums4) {
                if (umap.find(0-(c + d)) != umap.end()) {
                    result += umap[0 - (c + d)];
                }
            }
        }
        return result;
    }

    
};

int main() {
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {-2, -1};
    std::vector<int> nums3 = {-1, 2};
    std::vector<int> nums4 = {0, 2};

    Solution solution;
    int count = solution.fourSumCount(nums1, nums2, nums3, nums4);

    std::cout << "Count of tuples that sum up to zero: " << count << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        int hash[26] = {0};
        //记录每个字母出现的最远位置
        for (int i = 0; i < s.size(); i ++) {
            hash[s[i] - 'a'] = i;
        }
        int left = 0, right = 0;
        std::vector<int> result;
        //记录最大区间
        for (int i =  0; i < s.size(); i++) {
            right = std::max(right, hash[s[i] - 'a']);
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::string s = "ababcbacadefegdehijhklij";
    std::vector<int> result = sol.partitionLabels(s);
    std::cout << "[";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", "; // Properly format the output with commas and spaces
        }
    }
    std::cout << "]" << std::endl;
    return 0;
}
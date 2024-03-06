#include <iostream>
#include <unordered_map>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

class Solution {
public:
    std::unordered_map<int, int> ump;
    std::vector<int> result;
    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left);
        ump[cur->val] ++;
        traversal(cur->right);
        return;
    }

    std::vector<int> findMode(TreeNode* root) {
        ump.clear();
        traversal(root);
        int mostTrquentNum = 0;
        int maxCount = INT_MIN;
        for(const auto& pair:ump) {
            if (pair.second > maxCount) {
               maxCount = pair.second;
            }
        }
        for (const auto& pair:ump) {
            if (pair.second == maxCount) {
                result.push_back(pair.first);
            }
        }
        return result;

    }
};
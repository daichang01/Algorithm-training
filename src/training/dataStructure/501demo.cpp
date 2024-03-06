#include <iostream>
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
    std::vector<int> result;
    int count = 0;
    int maxCount = 0;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left);
        if (pre == nullptr) {
            count = 1;
        }
        else if (pre->val == cur->val) {
            count ++;
        }
        else {
            count = 1;
        }
        if (count == maxCount) {
            result.push_back(cur->val);
        }
        if (count > maxCount) {
            result.clear();
            maxCount = count;
            result.push_back(cur->val);
        }
        pre = cur;
        traversal(cur->right);
        return;
    }

    std::vector<int> findMode(TreeNode* root) {
        traversal(root);
        return result;
    }
};
int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    // 创建Solution实例并调用findMode方法
    Solution solution;
    std::vector<int> mode = solution.findMode(root);

    // 打印众数
    std::cout << "众数: ";
    for (int num : mode) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 清理内存
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
   
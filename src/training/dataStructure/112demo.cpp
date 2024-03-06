#include <iostream>
# include <memory>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

class Solution {
private:
    bool traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) return true;
        if (!cur->left && !cur->right) return false;

        if (cur->left) {
            count -= cur->left->val;
            if(traversal(cur->left, count)) return true;
            count += cur->left->val;
        }
        if (cur->right) {
            count -= cur->right->val;
            if (traversal(cur->right, count)) return true;
            count += cur->right->val;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }
};

int main() {
    // 创建树节点
    std::unique_ptr<TreeNode> root = std::make_unique<TreeNode>(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    // 检查路径和
    Solution solution;
    bool hasPath = solution.hasPathSum(root.get(), 22);

    // 输出结果
    if (hasPath) {
        std::cout << "There is a path with sum 22." << std::endl;
    } else {
        std::cout << "There is no path with sum 22." << std::endl;
    }

    // 清理分配的内存
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right->left;
    delete root->right;

    return 0;
}
#include <iostream>
#include <algorithm>

struct  TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

class Solution {
public:
    int getdepth (TreeNode* node) {
        if (node == nullptr) return 0;
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);
        int depth = 1 + std::max(leftdepth, rightdepth);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};

int main() {
    // 创建二叉树的节点
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 创建Solution实例
    Solution solution;

    // 计算并打印最大深度
    std::cout << "Maximum depth of the binary tree is: " << solution.maxDepth(root) << std::endl;

    // TODO: 释放分配的内存（在实际应用中很重要）
    // ...

    return 0;
}
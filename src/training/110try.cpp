#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

class Solution {
public:
    int getNodeheight(TreeNode* node) {
        if (node == nullptr) {return 0;}
        TreeNode* left = node->left;
        int leftheight = getNodeheight(left);
        if (leftheight == -1) return -1;
        TreeNode* right = node->right;
        int rightheight = getNodeheight(right);
        if (rightheight == -1) return -1;
        int result;
        if (std::abs(leftheight - rightheight) > 1) result = -1;
        else {result = 1 + std::max(leftheight, rightheight);}
        return result;
    }
    bool isBalanced(TreeNode* root) {
        int result = getNodeheight(root);
        if (result != -1) return true;
        else {return false;}
    }
};



int main() {
    // 创建树的节点
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // 可以继续添加更多的节点来构造树
    // ...

    // 创建Solution实例并检查树是否平衡
    Solution solution;
    bool isTreeBalanced = solution.isBalanced(root);

    if (isTreeBalanced) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    // 释放树的节点内存（简单示例，适用于小树）
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

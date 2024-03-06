#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

int main() {
    // 创建一个简单的对称二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);

    std::cout << "Is the tree symmetric? " << (result ? "Yes" : "No") << std::endl;

    // 清理分配的内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

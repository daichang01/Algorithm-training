#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            if (root == nullptr) {return root;}
        }
        std::swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

void printTree(TreeNode* root) {
    if (root != nullptr) {
        std::cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Original tree: ";
    printTree(root);
    std::cout << std::endl;

    Solution sol;
    root = sol.invertTree(root);

    std::cout << "Inverted tree: ";
    printTree(root);
    std::cout << std::endl;

    // 清理分配的内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
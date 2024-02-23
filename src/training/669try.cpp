#include <iostream>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}

};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < low) {
            TreeNode* right = trimBST(root->right,low, high);
            return right;
        }
        if (root->val > high) {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;

    }
};

void printInOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}

void deleteTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    // 创建测试树
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // 打印原始树
    std::cout << "原始树的中序遍历: ";
    printInOrder(root);
    std::cout << std::endl;

    
    Solution solution;
    TreeNode* result = solution.trimBST(root,3,6);
    //调用题目的方法进行验证

    // 打印更新后的树
    printInOrder(result);
    std::cout << std::endl;

    // 清理分配的内存
    deleteTree(result);
}
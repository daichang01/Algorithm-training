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
    TreeNode* constrcuctMaxinumBinaryTree(std::vector<int>& num) {
        TreeNode* node = new TreeNode(0);
        if (num.size() == 1) {
            node->val = num[0];
            return node;
        }
        int maxvalue = 0;
        int maxvalueIndex = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] > maxvalue) {
                maxvalue = num[i];
                maxvalueIndex = i;
            }
        }
        node->val = maxvalue;
        if(maxvalueIndex > 0) {
            std::vector<int> newVec(num.begin(), num.begin() + maxvalueIndex);
            node->left = constrcuctMaxinumBinaryTree(newVec);
        }
        if (maxvalueIndex < num.size()-1) {
            std::vector<int> newVec(num.begin() + maxvalueIndex + 1, num.end());
            node->right = constrcuctMaxinumBinaryTree(newVec);
        }
        return node;
    }
};

void printTree(TreeNode* node) {
    if (node != nullptr) {
        printTree(node->left);
        std::cout << node->val << " ";
        printTree(node->right);
    }
}

int main() {
    // 创建一个整数向量
    std::vector<int> nums = {3, 2, 1, 6, 0, 5};

    // 创建Solution实例并构建最大二叉树
    Solution solution;
    TreeNode* root = solution.constrcuctMaxinumBinaryTree(nums);

    // 打印构建的二叉树
    std::cout << "The constructed maximum binary tree (inorder): ";
    printTree(root);
    std::cout << std::endl;

    // 注意：这里没有删除TreeNode的实例，实际应用中应考虑内存管理

    return 0;
}
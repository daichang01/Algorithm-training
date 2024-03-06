#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        //第二步 判断终止条件
        if (root == nullptr) {
            return 0;
        }
        int countleft = 0;
        int countright=  0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while(left) {
            left = left->left;
            countleft ++;
        }
        while (right) {
            right = right->right;
            countright ++;
        }
        if (countleft == countright) {
            return (2 << countleft) - 1;
        }


        int leftnodes = countNodes(root->left);
        int rightnodes=  countNodes(root->right);
        int sum = leftnodes + rightnodes + 1;
        return sum; 
    }
};

int main() {
    // 创建二叉树的节点
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // 创建Solution实例
    Solution solution;

    // 计算并打印节点总数
    std::cout << "Total number of nodes in the binary tree is: " << solution.countNodes(root) << std::endl;

    // TODO: 释放分配的内存（在实际应用中很重要）
    // ...

    return 0;
}
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        TreeNode* root = new TreeNode(0);

        root->val = root1->val + root2->val;
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};

void printTree(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->val << " ";

        printTree(node->left);
        printTree(node->right);
    }
}

int main() {
    // 创建两个树的根节点
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    // 合并两棵树
    Solution solution;
    TreeNode* mergedTree = solution.mergeTrees(root1, root2);

    // 打印合并后的树
    std::cout << "The merged tree (inorder): ";
    printTree(mergedTree);
    std::cout << std::endl;

    // 注意：这里没有删除TreeNode的实例，实际应用中应考虑内存管理
    delete root1;
    delete root2;
    delete mergedTree;
    return 0;
}
#include <iostream>

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
    int pre = 0;

    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
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

int main() {
    // 创建一个示例树：
    //        5
    //       / \
    //      3   8
    //     / \   \
    //    1   4   9

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(9);

    Solution sol;
    root = sol.convertBST(root);

    // 打印转换后的树
    std::cout << "转换后的 BST 的中序遍历：";
    printInOrder(root);
    std::cout << std::endl;

    // 如有必要，释放内存
    // 删除树节点...

    return 0;
}
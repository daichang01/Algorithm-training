#include <iostream>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

class Solution{
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) return root;

        TreeNode* leftSearch = searchBST(root->left, val);
        if (leftSearch != nullptr) return leftSearch;

        return searchBST(root->right, val);
    }

    void printTree(TreeNode* root) {
        if (root == nullptr) return;
        std::cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    TreeNode* node = new TreeNode(3);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);

    Solution* sol = new Solution();
    TreeNode* newnode = sol->searchBST(node, 2);
    sol->printTree(newnode);

    // 注意：这里没有删除TreeNode的实例和Solution的实例，实际应用中应考虑内存管理

    return 0;
}

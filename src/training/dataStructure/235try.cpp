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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if (left != nullptr) return left;    
        }
        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (right != nullptr) return right;
        }
        return root;
    }
};

int main() {
    // Example tree creation
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution sol;
    TreeNode* p = root->left; // For example, node with value 2
    TreeNode* q = root->right; // For example, node with value 8

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    } else {
        std::cout << "No common ancestor found." << std::endl;
    }

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
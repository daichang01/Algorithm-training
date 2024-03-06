#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x) ,left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) {}
};

class Solution{
public:
    std::vector<int> vec;

    void traversal(TreeNode* root) {
        if (root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
        
    }

    bool isValidBST(TreeNode* root) {
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};

int main() {
    // Create nodes
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(3);

    // Construct the tree
    n1->left = n2;
    n1->right = n3;

    // Create a solution instance
    Solution solution;

    // Check if the tree is a valid BST
    bool result = solution.isValidBST(n1);
    if (result) {
        std::cout << "The tree is a valid BST." << std::endl;
    } else {
        std::cout << "The tree is not a valid BST." << std::endl;
    }

    // Clean up
    delete n1;
    delete n2;
    delete n3;

    return 0;
}
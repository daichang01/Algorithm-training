#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

class Solution {
public:
    int minval = INT_MAX;
    TreeNode* pre = nullptr;
    void traversal (TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        if (pre != nullptr) {
            minval = std::min(minval, root->val - pre->val);
        }
        pre = root;
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);

        return minval;
    }
};

int main() {
    // Create a sample tree: 4
    //                    /   \
    //                   2     6
    //                  / \   / \
    //                 1   3 5   7
    TreeNode* root = new TreeNode(4, 
                                  new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                                  new TreeNode(6, new TreeNode(5), new TreeNode(7)));

    Solution sol;
    std::cout << "Minimum difference: " << sol.getMinimumDifference(root) << std::endl;

    // Remember to delete the nodes to prevent memory leaks.
    // Delete operation is not shown here for brevity.
    // ...

    return 0;  
}
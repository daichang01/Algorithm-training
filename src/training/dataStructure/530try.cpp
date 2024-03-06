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
    std::vector<int> vec;
    void traversal (TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int minval = 10e5;
        for (int i = 0; i < vec.size() - 1; i++) {
            for (int j = i + 1; j < vec.size(); j++) {
                int temp = vec[j] - vec[i];
                if (temp < minval) {
                    minval = temp;
                }
            }
        }
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
                                  new TreeNode(2, new TreeNode(1), new TreeNode(2)),
                                  new TreeNode(6, new TreeNode(1), new TreeNode(7)));

    Solution sol;
    std::cout << "Minimum difference: " << sol.getMinimumDifference(root) << std::endl;

    // Remember to delete the nodes to prevent memory leaks.
    // Delete operation is not shown here for brevity.
    // ...

    return 0;  
}
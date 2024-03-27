#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> que;
        if (root != nullptr) que.push(root);

        int result = 0;

        while(!que.empty()) {
            int size = que.size();
            for (int i = 0 ; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) result = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }

};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);

    Solution sol;
    int res = sol.findBottomLeftValue(root);
    std::cout << res << std::endl;

    return 0;
}
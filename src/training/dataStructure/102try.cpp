#include <iostream>
#include <vector>
#include <queue>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> result;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            std::vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                vec.push_back(node->val);
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    std::vector<std::vector<int>> level_order = sol.levelOrder(root);

    // 打印层序遍历结果
    std::cout << "层序遍历：" << std::endl;
    for (const auto& level : level_order) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
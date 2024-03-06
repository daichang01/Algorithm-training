#include <iostream>
#include <memory>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            if(depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        if (root->left) {
            depth ++;
            traversal(root->left, depth);
            depth --;
        }
        if (root->right) {
            depth ++;
            traversal(root->right, depth);
            depth --;
        }
        return;
    }


    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};

int main() {
    // 使用智能指针创建树节点
    std::unique_ptr<TreeNode> node1 = std::make_unique<TreeNode>(1);
    std::unique_ptr<TreeNode> node2 = std::make_unique<TreeNode>(2);
    std::unique_ptr<TreeNode> node3 = std::make_unique<TreeNode>(3);
    std::unique_ptr<TreeNode> node4 = std::make_unique<TreeNode>(4);
    std::unique_ptr<TreeNode> node5 = std::make_unique<TreeNode>(5);
    std::unique_ptr<TreeNode> node6 = std::make_unique<TreeNode>(6);
    std::unique_ptr<TreeNode> node7 = std::make_unique<TreeNode>(7);

    // 组织成树（注意：这里我们使用裸指针，因为树的结构需要共享指针）
    node1->left = node2.get();
    node1->right = node3.get();
    node2->left = node4.get();
    node3->left = node5.get();
    node3->right = node6.get();
    node5->right = node7.get();

    // 使用 Solution 类的实例
    Solution solution;
    int result = solution.findBottomLeftValue(node1.get()); // 传递裸指针

    // 输出结果
    std::cout << "The bottom left value is: " << result << std::endl;

    // 智能指针自动释放内存
    return 0;
}
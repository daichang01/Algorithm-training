#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value):val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* left, TreeNode* right):val(value), left(left),right(right) {}

};

class Solution {
public:
    void Traversal (TreeNode* cur, std::vector<int>& vec) {
        if (cur == nullptr) {
            return;
        }
        Traversal(cur->left, vec);  
        Traversal(cur->right, vec);
        vec.push_back(cur->val);

        
    }
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> vec;
        Traversal(root, vec);
        return vec;

    }
};



int main() {
    // 创建节点
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);

    // 构建较复杂的二叉树
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6
    //        \
    //         7
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    node3->right = node6;
    node5->right = node7;

    // 创建Solution实例并进行遍历
    Solution sol;
    std::vector<int> result = sol.preorderTraversal(node1);

    // 打印遍历结果
    std::cout << "Preorder Traversal: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 清理分配的内存
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;

    return 0;
}

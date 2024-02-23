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
private:
    TreeNode* traversal(std::vector<int>& inorder, std::vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;
        
        int rootvalue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootvalue);

        if (postorder.size() == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootvalue) break;
        }

        std::vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        std::vector<int> rightInorder(inorder.begin() + delimiterIndex +1, inorder.end());

        postorder.resize(postorder.size() - 1);

        std::vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        std::vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
        
    }
public:
    TreeNode* buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};

void printTree(TreeNode* node) {
    if (node != nullptr) {
        printTree(node->left);
        printTree(node->right);
        std::cout << node->val << " ";

    }
}
int main() {
    // 创建中序和后序遍历的序列
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};

    // 创建Solution实例并重建二叉树
    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);

    // 打印重建后的二叉树结构
    std::cout << "The reconstructed tree (inorder): ";
    printTree(root);
    std::cout << std::endl;

    // 注意：这里没有删除TreeNode的实例，实际应用中应考虑内存管理

    return 0;
}
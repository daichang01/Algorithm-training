#include <iostream>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //1.确定终止条件
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            //左右子树都为空,说明自身是叶子节点
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            //左子树为空，右子树不为空
            else if (root->left == nullptr && root->right != nullptr) {
                return root->right;
            }
            //左子树不为空，右子树为空
            else if (root->left != nullptr && root->right == nullptr) {
                return root->left;
            }
            //左右子树都不为空
            else {
                TreeNode* cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                return root->right ;
            }

        }
        //2.确定单层递归
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
        
    }
};

void printInOrder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}

void deleteTree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    // 创建测试树
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    // 打印原始树
    std::cout << "原始树的中序遍历: ";
    printInOrder(root);
    std::cout << std::endl;

    // 删除节点
    Solution solution;
    root = solution.deleteNode(root, 3); // 例如，删除值为3的节点

    // 打印更新后的树
    std::cout << "删除节点后的中序遍历: ";
    printInOrder(root);
    std::cout << std::endl;

    // 清理分配的内存
    deleteTree(root);
}

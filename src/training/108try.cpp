#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* traversal(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;

    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        TreeNode* result = traversal(nums, 0, nums.size() -1);
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-10, -3, 0, 5, 9};  // 示例数组

    TreeNode* root = solution.sortedArrayToBST(nums);

    // 下面的代码是为了展示结果，需要遍历树并打印节点的值
    // 这里只是一个简单的示例，您可能需要一个更完整的树遍历函数来显示所有的节点
    if (root != nullptr) {
        std::cout << "Root of the BST: " << root->val << std::endl;
    }

    // 这里应该有代码来释放创建的树节点以避免内存泄漏
    // 但这超出了示例的范围

    return 0;
}
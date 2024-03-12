
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false; // Early return if the sum is odd.
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: zero sum is always possible.

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5}; // Example input
    bool canPart = sol.canPartition(nums);
    if(canPart) {
        cout << "Can partition: YES" << endl;
    } else {
        cout << "Can partition: NO" << endl;
    }
    return 0;
}

# include <iostream>
# include <unordered_set>

int getSum(int n) {
    int sum = 0;
    while(n) {
        sum += (n % 10)*(n % 10);
        n / 10;
    }
    return sum;
}


class Solution {
public:
    // 取数值各个位上的单数之和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        std::unordered_set<int> set;
        while(1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main() {
    Solution sol;
    
    int number = 19; // 示例数字，你可以更改这个数字来测试其他情况
    bool result = sol.isHappy(number);

    std::cout << "Is " << number << " a happy number? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
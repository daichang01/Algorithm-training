# include <iostream>
# include <string>
# include<algorithm>
class Solution {
public:
    void reverse(std::string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
    }
    std::string reverseStr(std::string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k <= s.size()) {
                reverse(s, i, i + k -1);
                continue;
            }

            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};

int main() {
    Solution solution;

    std::string test1 = "abcdefg";
    int k1 = 2;
    std::cout << "Original: " << test1 << ", k=" << k1 << ", Reversed: " << solution.reverseStr(test1, k1) << std::endl;

    std::string test2 = "hijklmnop";
    int k2 = 3;
    std::cout << "Original: " << test2 << ", k=" << k2 << ", Reversed: " << solution.reverseStr(test2, k2) << std::endl;

    // 可以添加更多测试用例

    return 0;
}
# include <iostream>
# include <string>

class Solution {
public:
    void reverse(std::string& s, int start, int end ) {
        for (int i = start, j = end; i < j; i++, j--) {
            std::swap(s[i], s[j]);
        }
    }

    void removeExtraSpace(std::string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {//遇到非空格就处理，即删除所有空格
                if (slow != 0) s[slow++] = ' ';//手动添加空格
                while (i < s.size() && s[i] != ' ') {
                    s[slow ++ ] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    std::string reverseWords(std::string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i -1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main () {
    Solution sol;
    std::string result;
    std::string s = " if you are   hero ";
    result = sol.reverseWords(s);
    std::cout << result << std::endl;
}
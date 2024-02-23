#include <iostream>
#include <vector>
// #include <string>

class Solution{
private:
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> path;
    void backtracking(const std::string& s, int startIndex) {
        //如果起始位置已经大于s的大小了，说明已经找到一组分割方案了
        if(startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s,startIndex, i)){
                //获取[startindex,i]在s中的子串
                std::string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else {
                continue;
            }
            backtracking(s, i+ 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const std::string& s , int start, int end)  {
        for ( int i = start, j = end; i< j; i++ , j--) {
            if(s[i] != s[j]) {
                return false;
            }

        }
        return true;
    }
public:
    std::vector<std::vector<std::string>> partirion(std::string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};

int main() {
    Solution solution;
    std::string s = "aab";
    std::vector<std::vector<std::string>> partitions = solution.partirion(s);

    std::cout << "所有可能的回文分割方式:\n";
    for (const auto& partition : partitions) {
        for (const auto& str : partition) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
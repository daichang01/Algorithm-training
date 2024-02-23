#include <iostream>
#include <vector>

class Solution{
private:
    std::vector<std::string> result;
    //startIndex:搜索开始位置， pointNum:添加逗点的数量
    void backtracking(std::string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            //逗点数量为3时，分隔结束
            //判断第四段子字符串是否合法，如果合法放进result中
            if (isValid(s, startIndex, s.size() -1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin()+i+1, '.');
                // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;//回溯
                s.erase(s.begin() + i + 1);

            }
            else break; //不合法直接结束本层循环
        }
    }

    bool isValid(const std::string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            //遇到非数字字符不合法
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
            num  = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
            
        }
        return true;
    }
public:
    std::vector<std::string> restoreIpAddress(std::string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) {
            return result;
        }
        backtracking(s, 0, 0);
        return result;
    }
};

int main() {
    Solution solver;

    std::string input = "25525511135";
    std::cout << "Input: " << input << std::endl;

    std::vector<std::string> ipAddresses = solver.restoreIpAddress(input);
    if (ipAddresses.empty()) {
        std::cout << "No valid IP addresses found." << std::endl;
    } else {
        std::cout << "Valid IP addresses:" << std::endl;
        for (const auto& ipAddress : ipAddresses) {
            std::cout << ipAddress << std::endl;
        }
    }

    return 0;
}
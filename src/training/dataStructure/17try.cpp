# include <iostream>
# include <vector>
# include <string>


class Solution {
private:
    const std::string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
public:
    std::vector<std::string> result;
    std::string s;
    void backtracinindexg(const std::string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        std::string letters = letterMap[digit];
        for (int i  = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);
            backtracinindexg(digits, index + 1);
            s.pop_back();
        }
    }
    std::vector<std::string> letterCombinations(std::string digits) {
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backtracinindexg(digits, 0);
        return result;
    }
};

int main() {
    std::string digits = "234";
    Solution sol;
    std::vector<std::string> result = sol.letterCombinations(digits);
    for (const std::string res:result) {
        std::cout << res <<std::endl;
    }
    return 0;
}


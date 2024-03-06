# include <iostream>
# include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main () {
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution sol;
    if (sol.isAnagram(s,t)) {
        std::cout << "true" <<std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
}
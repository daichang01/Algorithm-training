#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char,int> umap;
        for (char a:ransomNote) {
            umap[a] ++;
        }
        for (char b:magazine) {
            if(umap.find(b) != umap.end()) {
                umap[b] --;
            }
        }
        bool result = true;
        for (const auto& pair : umap) {
            if (pair.second > 0) {
                result = false;
                break; // 如果发现一个值大于 0，则退出循环
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    std::string ransomNote = "aabbcdc";
    std::string magazine = "abccbaabccba";

    bool canBeConstructed = solution.canConstruct(ransomNote, magazine);

    if (canBeConstructed) {
        std::cout << "Ransom note can be constructed from the magazine." << std::endl;
    } else {
        std::cout << "Ransom note cannot be constructed from the magazine." << std::endl;
    }

    return 0;
}
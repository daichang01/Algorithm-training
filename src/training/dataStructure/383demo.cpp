# include <iostream>
# include <string>
class Solution {
    public:
        bool canConstruct(std::string ransomNote, std::string magazine) {
        int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
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
# include <iostream>
#include <string>

class Solution {
public:
    void reverseString(std::string& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            std::swap(s[i],s[j]);
        }
        
    }

    std::string reverseStr(std::string s, int k) {
        if (s.size() < 2 * k) return " ";
        std::string str1;
        std::string tmp;
        for (int i = 0; i <  k; i++) {
            str1[i] = s[i];
        }
        tmp = s - str1; //fail
        reverseString(str1);
        std::string str2;
        std::string str3;
        for (int i = 2 * k, j = 0; i < s.size(); i++, j++) {
            str2[j] = s[i];
        }
        if ((s.size() - 2*k) < k) {
            reverseString(str2);
        }
        else {
            for (int i = 0; i < k; i++) {
                str3[i] = str2[i];
            }
            reverseString(str3);
            
        }
        
    }
};
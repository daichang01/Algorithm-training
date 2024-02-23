#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int result = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int index = s.size() - 1; //饼干数组下标
        for (int i = g.size() - 1 ; i >= 0; i--) { //遍历胃口
            while(index >= 0 && s[index] >= g[i]) {// 遍历饼干
                result ++;
                index --;
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> g = {1,2};
    std::vector<int> s = {1,2,3};
    int result = sol.findContentChildren(g, s);
    std::cout << result << std::endl;
    return 0;
}
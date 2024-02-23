#include <iostream>
#include <unordered_map>

int main () {
    int s;
    std::cin >> s;
    while (s--) {
        int n;
        std::cin >> n;
        int k,d;
        std::unordered_map<int,int> umap;
        while (n--) {
            std::cin >> k >> d;
            umap[k] = d;
        }
        int x;
        std::cin >> x;
        bool flag = true;
        for (const std::pair<int, int>& kv:umap) {
            if (kv.second == x) {
                std::cout << kv.first << std::endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << "Can't open the door." << std::endl;
        }
        
    }
}
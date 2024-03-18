#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    // 初始化map
    std::map<std::string, int> p{{"apple", 2}, {"banana", 5}, {"cherry", 3}};

    // 遍历map
    for (auto map1 = p.cbegin(); map1 != p.cend(); ++map1) {
        std::cout << map1->first << " - " << map1->second << std::endl;
    }

    // 插入元素
    p.insert({"orange", 4});
    p.insert(std::pair<std::string, int>("grape", 6));

    // 使用pair接收insert的返回值
    auto insertResult = p.insert({"apple", 1}); // apple已存在，插入不成功
    std::cout << "Insertion successful? " << insertResult.second << std::endl;

    // 将map的内容复制到vector<pair>中，并根据second排序
    std::vector<std::pair<std::string, int>> result(p.begin(), p.end());
    std::sort(result.begin(), result.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    // 输出排序后的vector内容
    for (const auto &item : result) {
        std::cout << item.first << " - " << item.second << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> wordCount;
    string words[] = {"apple", "banana", "apple", "orange", "banana", "apple"};

    for(const auto& word : words) {
        wordCount[word]++;
    }

    // 输出每个单词出现的次数
    for(const auto& pair : wordCount) {
        cout << pair.first << " appears " << pair.second << " times\n";
    }
}
